// H5_bitmap_exporter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "detiling/DirectXTexXbox.h"

#include <iostream>
#include <DirectXTex.h>


#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <algorithm>

#include <stdio.h>
#include <sys/types.h>
//#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#include <locale>  
#include <codecvt>
#include "detiling/DirectXTexp.h"


using namespace std;
#pragma pack(push, 1)
struct dat_texture {
    uint32_t width;
    uint32_t height;
    uint32_t image_count;
    uint16_t unk1;
    uint16_t unk2;
    uint32_t data_length;
};
#pragma pack(pop)


bool is_short_header(DXGI_FORMAT format) {
    switch (format) {
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R8G8_UNORM:
    case DXGI_FORMAT_R16_UNORM:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_A8_UNORM:
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
    case DXGI_FORMAT_BC1_UNORM:
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC4_SNORM:
    case DXGI_FORMAT_BC5_SNORM:
    case DXGI_FORMAT_B5G6R5_UNORM:
    case DXGI_FORMAT_B5G5R5A1_UNORM:
    case DXGI_FORMAT_R8G8_SNORM:
    case DXGI_FORMAT_R8G8B8A8_SNORM:
    case DXGI_FORMAT_R16G16_SNORM:
    case DXGI_FORMAT_B8G8R8A8_UNORM:
    case DXGI_FORMAT_B8G8R8X8_UNORM:
    case DXGI_FORMAT_B4G4R4A4_UNORM:
    case DXGI_FORMAT_YUY2:
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R16G16B16A16_SNORM:
    case DXGI_FORMAT_R32G32_FLOAT:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_R16_FLOAT:
    /*  // only short header if conversion flag 'DDS_FLAGS_FORCE_DX9_LEGACY'
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_BC1_UNORM_SRGB:
    case DXGI_FORMAT_BC2_UNORM_SRGB:
    case DXGI_FORMAT_BC3_UNORM_SRGB:
    case DXGI_FORMAT_BC4_UNORM:
    case DXGI_FORMAT_BC5_UNORM:
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: */
        return true;
    }
    return false;
}

bool is_exportable_format(DXGI_FORMAT format) {
    switch (format){
        case DXGI_FORMAT_R32G32B32A32_FLOAT:
        case DXGI_FORMAT_R16G16B16A16_FLOAT:
        case DXGI_FORMAT_R16G16B16A16_UNORM:
        case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
        case DXGI_FORMAT_R10G10B10A2_UNORM:
        case DXGI_FORMAT_B5G5R5A1_UNORM:
        case DXGI_FORMAT_B5G6R5_UNORM:
        case DXGI_FORMAT_R32_FLOAT:
        case DXGI_FORMAT_R16_FLOAT:
        case DXGI_FORMAT_R16_UNORM:
        case DXGI_FORMAT_R8_UNORM:
        case DXGI_FORMAT_A8_UNORM:
        case DXGI_FORMAT_R8G8B8A8_UNORM:
        case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
        case DXGI_FORMAT_B8G8R8A8_UNORM:
        case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
        case DXGI_FORMAT_B8G8R8X8_UNORM:
        case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
            return true;
    }
    return false;
}


void try_export_texture(dat_texture dat_header, char* dat_bytes, DXGI_FORMAT target_format, uint16_t tilemode, string output_file) {

    // ////////////////////// //
    // SETUP DDS HEADER DATA //
    // //////////////////// //
    size_t header_size = sizeof(uint32_t) + 124; // sizeof(DirectX::DDS_HEADER); + sizeof(DirectX::DDS_HEADER_DXT10);
    // NOTE: DDS_HEADER_DXT10 size is added becuaused it doesn't matter if we overallocate, this is to simplify the process (so we dont have to check for the short header types)
    
    // configure meta data
    DirectX::TexMetadata meta = {};
    meta.depth = 1;
    meta.arraySize = 1;
    meta.mipLevels = 1; 
    meta.miscFlags = 8000000; // something to do with tile mode
    meta.miscFlags2 = 0;
    meta.dimension = (DirectX::TEX_DIMENSION)3; // TEX_DIMENSION_TEXTURE2D

    // apply data from texture header
    meta.width = dat_header.width;
    meta.height = dat_header.height;
    // apply our suspected texture format
    meta.format = target_format;

    header_size += sizeof(DDS_HEADER_XBOX_p); // xbox mode

    // ////////////////////////////////// //
    // CONVERT TEXTURE DATA TO DDS IMAGE //
    // //////////////////////////////// //
    char* DDSheader_dest = new char[header_size + dat_header.data_length]; // NOTE: this needs to be cleaned up
    size_t output_header_size = 0;
    HRESULT hr = EncodeDDSHeader(meta, DirectX::DDS_FLAGS_NONE, (void*)DDSheader_dest, header_size, output_header_size);
    if (!SUCCEEDED(hr)) throw exception("failed to encode DDS header");
    if (header_size < output_header_size) throw exception("encoded DDS header did not match expected size"); // realistically this can be ignored, as we're only allocating extra space? // updated
    // apparently that doesn't matter in xbox mode

    // then write the bitmap data
    memcpy(DDSheader_dest+header_size, dat_bytes, dat_header.data_length);


    DirectX::ScratchImage DDS_image = {};
    // //////////////////////////////// //
    // UNSWIZZLE THE TEXTURE IF NEEDED //
    // ////////////////////////////// //
    DDS_HEADER_p* encoded_header = (DDS_HEADER_p*)(DDSheader_dest + sizeof(uint32_t));
    encoded_header->ddspf.flags |= 4; // DDS_FOURCC
    encoded_header->ddspf.fourCC = 0x584F4258; // 'XBOX' backwards

    DDS_HEADER_XBOX_p* encoded_xbox_header = (DDS_HEADER_XBOX_p*)(DDSheader_dest + sizeof(uint32_t) + 124); // sizeof(DirectX::DDS_HEADER);
    // luckily, if the original format was the DX10 header, then it encodes the first 5 parameters for this header: dxgiFormat, resourceDimension, miscFlag, arraySize & miscFlags2
    // thats because we just pretend its a regular DDS header, and are converting it in place (which works because the xbox version is larger than the regular one)
    // ok apparently theres a few textures that do NOT use the DX10 extension, so we have to write that data anyway !!!!
    //if (is_short_header(meta.format)) {
        encoded_xbox_header->dxgiFormat = meta.format;
        encoded_xbox_header->resourceDimension = meta.dimension;
        encoded_xbox_header->miscFlag = meta.miscFlags & ~4; // TEX_MISC_TEXTURECUBE; // this is just what is done in the regular encode
        // something something array count | TEX_MISC_TEXTURECUBE flag
        encoded_xbox_header->arraySize = meta.arraySize;
        encoded_xbox_header->miscFlags2 = meta.miscFlags2;
    //}

    encoded_xbox_header->tileMode = tilemode; // bitmap_details->tileMode; // Xbox::c_XboxTileModeLinear;
    encoded_xbox_header->baseAlignment = 32768; // this is the value that the Xbox layout is saying it should be?? // can be anything other than 0??
    encoded_xbox_header->dataSize = dat_header.data_length;
    encoded_xbox_header->xdkVer = 0;



    assert(meta.width > 0 && meta.height > 0 && meta.depth > 0);
    assert(meta.arraySize > 0);
    assert(meta.mipLevels > 0);
    static_assert(sizeof(size_t) == 8, "Not a 64-bit platform!");

    // verify our format has enough room
    size_t img_count = 0;
    size_t required_bytes_count = 0;
    DirectX::Internal::DetermineImageArray(meta, DirectX::CP_FLAGS_NONE, img_count, required_bytes_count);
    if (required_bytes_count > dat_header.data_length) 
        throw exception("insufficient bytes for DDS format");


    // ok, now our image should be good for loading
    //DirectX::TexMetadata* test = nullptr;
    Xbox::XboxImage xbox_image = {};
    hr = Xbox::LoadFromDDSMemory(DDSheader_dest, header_size+dat_header.data_length, nullptr, xbox_image);
    if (hr == 0x80070026) throw exception("DDS format requires more space than available");
    else if (FAILED(hr)) 
        throw exception("failed to load DDS from memory");

    hr = Xbox::Detile(xbox_image, DDS_image); // this detiles xbox_image to DDS_image
    if (!SUCCEEDED(hr)) throw exception("failed to detile dds");

    // //////////////////////////////////////////// //
    // PC VERSION CODE THAT WE AREN'T GOING TO USE //
    // ////////////////////////////////////////// //
    //hr = DirectX::LoadFromDDSMemory(DDSheader_dest, header_size+dat_header.data_length, (DirectX::DDS_FLAGS)0, nullptr, DDS_image);
    //if (hr == 0x80070026) throw exception("DDS format requires more space than available");
    //else if (FAILED(hr)) throw exception("failed to load DDS from memory");
    
    
    // /////////////////////////////////////// //
    // CONVERT DDS IMAGE TO EXPORTABLE FORMAT //
    // ///////////////////////////////////// //
    DirectX::ScratchImage decompressedImage = {};
    const DirectX::Image* final_img = nullptr;
    if (DirectX::IsCompressed(meta.format)) { // if BC, then we need to decompress the image to convert it
        hr = DirectX::Decompress(DDS_image.GetImages(), DDS_image.GetImageCount(), DDS_image.GetMetadata(), DXGI_FORMAT_R8G8B8A8_UNORM, decompressedImage);
        if (FAILED(hr)) throw exception("failed to decompress DDS image");
        final_img = decompressedImage.GetImage(0, 0, 0);
    }else if (!is_exportable_format(meta.format)){ // BC bitmaps should always convert to that format anyway, so they shouldn't need to convert
        hr = DirectX::Convert(DDS_image.GetImages(), DDS_image.GetImageCount(), DDS_image.GetMetadata(), DXGI_FORMAT_R8G8B8A8_UNORM, DirectX::TEX_FILTER_DEFAULT, DirectX::TEX_THRESHOLD_DEFAULT, decompressedImage);
        if (FAILED(hr)) throw exception("failed to convert DDS image");
        final_img = decompressedImage.GetImage(0, 0, 0);
    }else {
        // this is bad as it means the image will call the deleter twice!!!
        //memcpy(&decompressedImage, &DDS_image, sizeof(DDS_image)); // move DDS_image to decompressed image
        final_img = DDS_image.GetImage(0, 0, 0);
    }

    // ///////////////////////////////////// //
    // EXPORT THE TEXTURE TO A REGULAR FILE //
    // /////////////////////////////////// //
    wstring wide_export_path (output_file.begin(), output_file.end());
    hr = DirectX::SaveToWICFile(*final_img, DirectX::WIC_FLAGS_NONE, DirectX::GetWICCodec(DirectX::WIC_CODEC_PNG), wide_export_path.c_str());
    if (FAILED(hr)) throw exception("failed to save to WIC file");
}

void flip_bytes(int int_size, char* source, int byte_count) {
    if (int_size % 2 == 1) throw exception("cant flip odd int size");

    for (int i = 0; i < byte_count; i += int_size) {
        if (byte_count < i + (int_size-1)) throw exception("cant flip final bytes");

        for (int int_byte_index = 0; int_byte_index < int_size/2; int_byte_index++) {
            int opposite_index = int_size - (int_byte_index+1);
            char opposite = source[i + opposite_index];
            // then swap
            source[i + opposite_index] = source[i + int_byte_index];
            source[i + int_byte_index] = opposite;
    }}
}

std::string version = "0.2.1";
int main(int argc, char* argv[]){
    try{
        HRESULT hr = CoInitialize(NULL); // used for the WIC file exporting? i think
        if (FAILED(hr)) {
            std::cout << "failed to coInitialize Application (idk what this means), aborting process";
            system("pause");
            return 0;}
        std::cout << "img export test version: " << version << "\n";

        // ////////////////////////////// //
        // MANUAL CONSOLE CONFIGURATIONS //
        // //////////////////////////// //
        //string filepath = "C:\\Users\\Joe bingle\\Downloads\\brooen_stuff\\test\\Arrow_selector_left.dat"; // get filepath from args
        //string filepath = "C:\\Users\\Joe bingle\\Downloads\\brooen_stuff\\test2\\Cutthroat_s.dat"; 
        //string filepath = "C:\\Users\\Joe bingle\\Downloads\\brooen_stuff\\test3\\Banshee_n.dat";
        //string filepath = "C:\\Users\\Joe bingle\\Downloads\\brooen_stuff\\test4\\Banshee.dat";
        string filepath = "C:\\Users\\Joe bingle\\Downloads\\brooen_stuff\\test5\\Engine_Prop_a.dat";

        // /////////////////////////// //
        // READ BITMAP FILE & PROCESS //
        // ///////////////////////// //
        ifstream file_stream(filepath, ios::binary | ios::ate);
        if (!file_stream.is_open()) throw exception("failed to open speficied file");

        std::streamsize file_size = file_stream.tellg();
        if (file_size < sizeof(dat_texture)) throw exception("file contained too few bytes to fit texture header");

        // read the whole file
        char* file_bytes = new char[file_size]; // cleaned up when process terminates (not cleaned up)
        file_stream.seekg(0, ios::beg);
        file_stream.read(file_bytes, file_size);
        file_stream.close();

        // ///////////////////////////////// //
        // FORMAT DATA & CONVERT ENDIANNESS //
        // //////////////////////////////// //
        flip_bytes(4, file_bytes, 20);

        dat_texture tex_header = *((dat_texture*)file_bytes);
        char* tex_data = file_bytes + sizeof(dat_texture);
        flip_bytes(2, tex_data, tex_header.data_length);

        // 0B 1A 20 01 52 (52) means format 70,71,72 with flip interval of 2
        // 0B 1A 20 01 71 (71) means format 82,83 with flip interval of 2


        // ///////////////////////////////// //
        // PROCESS FILE INTO ALL DX FORMATS //
        // /////////////////////////////// //
        //for (int i = 1; i < 133; i++) {

        //    // get current dxgi format
        //    DXGI_FORMAT curr_format = (DXGI_FORMAT)i;
        //    // get output path
        //    string output_path = filepath + std::to_string(i) + ".png";

        //    // then try and do it
        //    try {
        //        try_export_texture(tex_header, tex_data, curr_format, output_path);
        //        std::cout << "success: " << i <<"\n";
        //    }
        //    catch (exception ex) {
        //        std::cout << "failure: " << i << " reason: " << ex.what() << "\n";
        //    }
        //}


        // //////////////////////////////// //
        // PROCESS FILE INTO ALL TILEMODES //
        // ////////////////////////////// //
        for (int i = 27; i < 1000; i++) {
            // get current dxgi format
            DXGI_FORMAT curr_format = (DXGI_FORMAT)i;
            // get output path
            string output_path = filepath + "71_tm" + std::to_string(i) + ".png";

            // then try and do it
            try {
                try_export_texture(tex_header, tex_data, (DXGI_FORMAT)71, i, output_path);
                std::cout << "success: " << i <<"\n";
            }
            catch (exception ex) {
                std::cout << "failure: " << i << " reason: " << ex.what() << "\n";
            }
        }


        //std::cout << "exporting completed!\n";
        //system("pause"); 
        return 0;}
    catch (exception ex){
        std::cout << "complete process failure: " << ex.what() << "\n";
        //system("pause");
        return 0;}
}