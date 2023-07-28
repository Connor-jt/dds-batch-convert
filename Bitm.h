#pragma once
/*
; CONTENT AUTOGENERATED BY CODENAME ATRIOX: PLUGIN CONVERTOR (lord zedd edition)
; CONVERTOR VERSION: Zedd_0.4.1
; SOURCE TIMESTAMP: [EXAMPLE]
; SOURCE GAME VERSION: [EXAMPLE]
; SOURCE PLUGIN: bitm
; GENERATED TIMESTAMP: 29/07/2023 -> 1:54:33 AM
*/

#include "commons.h"
#pragma pack(push, 1)

struct bitm {
    struct __internal_struct {
        int32_t global_tag_ID_;
        uint8_t local_tag_handle__[4];
    };
    enum __Usage_choose_how_you_are_using_this_bitmap : uint32_t {
        Diffuse_Map = 0,
        Linear_Control_Map = 1,
        Specular_Map = 2,
        Bump_Map__from_Height_Map_ = 3,
        Detail_Bump_Map__from_Height_Map___fades_out_ = 4,
        Detail_Map = 5,
        Self_Illum_Map = 6,
        Change_Color_Map = 7,
        Cube_Map__Reflection_Map_ = 8,
        HDR_Cube_Map = 9,
        Sprite__Additive__Black_Background_ = 10,
        Sprite__Blend__White_Background_ = 11,
        Sprite__Double_Multiply__Gray_Background_ = 12,
        Interface_Bitmap = 13,
        Warp_Map__EMBM_ = 14,
        Vector_Map = 15,
        _3D_Texture = 16,
        Float_Map__WARNING__HUGE_ = 17,
        Half_float_Map__HALF_HUGE_ = 18,
        Height_Map__for_Parallax_ = 19,
        ZBrush_Bump_Map__from_Bump_Map_ = 20,
        Normal_Map__aka_zbump_ = 21,
        Detail_ZBrush_Bump_Map = 22,
        Detail_Normal_Map = 23,
        Blend_Map__linear_for_terrains_ = 24,
        Palettized_____effects_only = 25,
        CHUD_related_bitmap = 26,
        Lightmap_Array = 27,
        Water_Array = 28,
        Interface_Sprite = 29,
        Interface_Gradient = 30,
        Material_Map = 31,
        Smoke_Warp = 32,
        Mux_Material_Blend_Map = 33,
        Cubemap_Gel = 34,
        Lens_Flare_gamma_2_2____effects_only = 35,
        Signed_Noise = 36,
        Roughness_Map__auto_ = 37,
        Normal_Map__from_Standard_Orientation_of_Maya__Modo__Zbrush_ = 38,
        Color_Grading = 39,
        Detail_Normal_Map__from_Standard_Orientation_with_distance_fade_ = 40,
        Diffuse_Texture_Array = 41,
        Palettized_Texture_Array = 42,
        Uncompressed_palette__no_MIPs_ = 43,
        Gobo = 44,
        Flow_Map = 45,
        Linear_Control_Map_Texture_Array = 46,
        Bump_Map__from_Height_Map__Texture_Array = 47,
        Detail_Map_Texture_Array = 48,
        Self_Illum_Map_Texture_Array = 49,
        Sprite__Additive__Black_Background__Texture_Array = 50,
        Sprite__Blend__White_Background__Texture_Array = 51,
        Sprite__Double_Multiply__Gray_Background__Texture_Array = 52,
        Warp_Map__EMBM__Texture_Array = 53,
        Normal_Map__aka_zbump__Texture_Array = 54,
        Detail_Normal_Map_Texture_Array = 55,
        Lens_Flare_gamma_2_2____effects_only_Texture_Array = 56,
        Normal_Map__from_Standard_Orientation_of_Maya__Modo__Zbrush__Texture_Array = 57,
        Detail_Normal_Map__from_Standard_Orientation_with_distance_fade__Texture_Array = 58,
        Flow_Map_Texture_Array = 59,
        Sprite_Normal_Map = 60,
    };
    struct __Flags {
        uint32_t content;
        bool bitmap_is_TILED_affects_how_height_maps_are_converted_to_bump_maps() { return (content & 0b00000000000000000000000000000001); }
        bool use_less_blurry_bump_map_uses_a_sharper__and_noisier__method_of_calculating_bump_maps_from_height_maps() { return (content & 0b00000000000000000000000000000010); }
        bool dither_when_compressing_lets_the_compressor_use_dithering() { return (content & 0b00000000000000000000000000000100); }
        bool generate_random_sprites_repopulates_the_manual_sequences_with_random_sprites_upon_reimport() { return (content & 0b00000000000000000000000000001000); }
        bool using_tag_interop_and_tag_resource___FOR_INTERNAL_USE_ONLY___DO_NOT_MODIFY() { return (content & 0b00000000000000000000000000010000); }
        bool ignore_alpha_channel_if_you_have_an_alpha_channel_but_do_not_care_about_it__set_this_flag() { return (content & 0b00000000000000000000000000100000); }
        bool alpha_channel_stores_TRANSPARENCY_if_your_alpha_channel_represents_transparency__alpha_blend_or_alpha_test_only___set_this_bit_to_stop_color_bleeding_on_edges() { return (content & 0b00000000000000000000000001000000); }
        bool preserve_alpha_channel_in_mipmaps_for_ALPHA_TEST_prefer_to_use_alpha_value_as_a_weight_to_build_mipmap__this_will_artificially_thicken_the_alpha_channel_in_mip_maps__which_can_keep_your_bitmap_from_disappearing_in_the_distance_when_you_are_using_alpha_test() { return (content & 0b00000000000000000000000010000000); }
        bool only_use_on_demand_UI_on_demand_bitmap_this_bitmap_will_always_be_demand_loaded__only_supported_by_UI() { return (content & 0b00000000000000000000000100000000); }
        bool generate_tight_bounds_generate_a_polygonal_bounding_box_around_the_non_empty_pixels_to_save_fill_rate_cost() { return (content & 0b00000000000000000000001000000000); }
        bool tight_bounds_from_alpha_channel_unchecked__tight_bounds_are_generated_from_the_color_channel() { return (content & 0b00000000000000000000010000000000); }
        bool do_not_generate_required_section_bitmap_will_have_data_split_between_medium_and_low_optional_sections() { return (content & 0b00000000000000000000100000000000); }
        bool unused() { return (content & 0b00000000000000000001000000000000); }
        bool apply_max_resolution_after_slicing_allows_use_of__quot_max_resolution_quot__on_bitmaps_that_have_multiple_frames__but_may_be_buggy____() { return (content & 0b00000000000000000010000000000000); }
        bool generate_black_point_tight_bounds_generate_a_set_of_polygonal_bounding_boxes_for_various_alpha_black_points() { return (content & 0b00000000000000000100000000000000); }
        bool Pre_filter_cubemaps_Apply_cosine_power_weighted_cone_filter_to_entire_cubemap_instead_of_filtering_each_face_as_separate_2D_image() { return (content & 0b00000000000000001000000000000000); }
    };
    enum __curve_mode_automatic_chooses_FAST_if_your_bitmap_is_bright__and_PRETTY_if_your_bitmap_has_dark_bits : uint8_t {
        choose_best_will_choose_FAST_if_your_bitmap_is_bright = 0,
        force_FAST_forces_FAST_mode__but_causes_banding_in_dark_areas = 1,
        force_PRETTY_chooses_the_best_looking_curve__probably_slower = 2,
    };
    enum __force_bitmap_format_overrides_the_format_defined_by_usage : uint16_t {
        Use_Default__defined_by_usage_ = 0,
        Best_Compressed_Color_Format = 1,
        Best_Uncompressed_Color_Format = 2,
        Best_Compressed_Bump_Format = 3,
        Best_Uncompressed_Bump_Format = 4,
        Best_Compressed_Monochrome_Format = 5,
        Best_Uncompressed_Monochrome_Format = 6,
        Best_Compressed_Monochrome_Format_without_alpha = 7,
        unused2_ = 8,
        unused3_ = 9,
        unused4_ = 10,
        unused5_ = 11,
        unused6_ = 12,
        ____Color_and_Alpha_formats____ = 13,
        bc1_unorm__a_k_a__DXT1___Compressed_Color___Color_Key_Alpha__DXT1__Compressed_Color___Color_Key_Alpha__ = 14,
        bc2_unorm__a_k_a__DXT3___Compressed_Color___4_bit_Alpha__DXT3__Compressed_Color___4_bit_Alpha__ = 15,
        bc3_unorm__a_k_a__DXT5___Compressed_Color___Compressed_8_bit_Alpha__DXT5__Compressed_Color___Compressed_8_bit_Alpha__ = 16,
        _24_bit_Color___8_bit_Alpha = 17,
        _8_bit_Monochrome___8_bit_Alpha = 18,
        ___Channel_Mask__3_bit_Color___1_bit_Alpha_ = 19,
        ___30_bit_Color___2_bit_Alpha = 20,
        ___48_bit_Color___16_bit_Alpha = 21,
        ___HALF_Color___Alpha = 22,
        ___FLOAT_Color___Alpha = 23,
        r8_unorm__8_bit_Intensity_replicated_to_RGBA__AY8__8_bit_Intensity_replicated_to_ARGB__ = 24,
        DEPRECATED_DXT3A__4_bit_Intensity_replicated_to_ARGB__DXT3A__4_bit_Intensity_replicated_to_ARGB__ = 25,
        bc4_unorm_rrrr__a_k_a__DXT5A___Compressed_Intensity_replicated_to_ARGB__bc4_unorm_000r__a_k_a__DXT5A___Compressed_Intensity_replicated_to_ARGB__ = 26,
        Compressed_Monochrome___Alpha = 27,
        b4g4r4a4__12_bit_color___4_bit_alpha__A4R4G4B4__12_bit_color___4_bit_alpha__ = 28,
        ____Color_only_formats____ = 29,
        _8_bit_Monochrome = 30,
        ___Compressed_24_bit_Color = 31,
        ___32_bit_Color__R11G11B10_ = 32,
        ___16_bit_Monochrome = 33,
        ___16_bit_Red___Green_Only = 34,
        ___16_bit_signed_RGBA____16_bit_signed_ARGB_ = 35,
        ___HALF_Red_Only = 36,
        ___FLOAT_Red_Only = 37,
        ___HALF_Red___Green_Only = 38,
        ___FLOAT_Red___Green_Only = 39,
        ___HALF_Monochrome = 40,
        DEPRECATED_Compressed_4_bit_Monochrome_Compressed_4_bit_Monochrome_ = 41,
        Compressed_Interpolated_Monochrome = 42,
        bc6h_uf16__HDR_RGB_unsigned_half_float__DXT5_red_ = 43,
        bc6h_sf16__HDR_RGB_signed_half_float__DXT5_green_ = 44,
        bc7_unorm__High_quality_bc3__DXT5_blue_ = 45,
        ____Alpha_only_formats____ = 46,
        DEPRECATED_DXT3A__4_bit_Alpha__DXT3A__4_bit_Alpha__ = 47,
        bc4_unorm_000r__a_k_a__DXT5A___8_bit_Compressed_Alpha__DXT5A__8_bit_Compressed_Alpha__ = 48,
        _8_bit_Alpha = 49,
        unused13_ = 50,
        unused14_ = 51,
        unused15_ = 52,
        ____Normal_map_formats____ = 53,
        bc5_snorm__a_k_a__DXN__Compressed_Normals__better__DXN_Compressed_Normals__better__ = 54,
        DEPRECATED_CTX1_Compressed_Normals__smaller__CTX1_Compressed_Normals__smaller__ = 55,
        _16_bit_Normals = 56,
        _32_bit_Normals = 57,
        _8_bit_4_channel_Vector = 58,
    };
    struct __usage_override {
        enum __bitmap_curve : uint32_t {
            unknown = 0,
            xRGB__gamma_about_2_0__SRGB__gamma_2_2__ = 1,
            gamma_2_0 = 2,
            linear = 3,
            offset_log = 4,
            sRGB__gamma_2_2_ = 5,
            Rec709__gamma_2_2_ = 6,
        };
        struct __flags {
            uint8_t content;
            bool Ignore_Curve_Override() { return (content & 0b00000001); }
            bool Dont_Allow_Size_Optimization() { return (content & 0b00000010); }
            bool Swap_Axes() { return (content & 0b00000100); }
            bool Pre_filter_cubemaps() { return (content & 0b00001000); }
        };
        enum __slicer : uint8_t {
            Automatically_Determine_Slicer = 0,
            No_Slicing__each_source_bitmap_generates_one_element_ = 1,
            Color_Plate_Slicer = 2,
            Cube_Map_Slicer = 3,
            Color_Grading_Slicer = 4,
        };
        struct __dicer_flags {
            uint8_t content;
            bool Convert_Plate_Color_Key_to_Alpha_Channel() { return (content & 0b00000001); }
            bool Rotate_Cube_Map_to_Match_DirectX_Format() { return (content & 0b00000010); }
            bool Sprites__Shrink_Elements_to_Smallest_Non_Zero_Alpha_Region() { return (content & 0b00000100); }
            bool Sprites__Shrink_Elements_to_Smallest_Non_Zero_Color_And_Alpha_Region() { return (content & 0b00001000); }
            bool Unsigned____Signed_Scale_and_Bias() { return (content & 0b00010000); }
            bool Color_Grading_sRGB_Correction() { return (content & 0b00100000); }
            bool Color_Grading_Rec709_Correction() { return (content & 0b01000000); }
        };
        enum __packer : uint8_t {
            No_packing = 0,
            Sprite_Pack__packs_elements_into_as_few_bitmaps_as_possible_ = 1,
            Sprite_Pack_if_needed__packs_elements_into_as_few_bitmaps_as_possible_ = 2,
            _3D_Pack__packs_elements_into_a_3D_bitmap_ = 3,
        };
        struct __packer_flags {
            uint8_t content;
            bool Shrink_Sprite_Texture_Pages_Tightly_to_Content() { return (content & 0b00000001); }
        };
        enum __type : uint8_t {
            _2D_texture = 0,
            _3D_texture = 1,
            cube_map = 2,
            array = 3,
        };
        enum __smallest_mip : uint8_t {
            _1_pixel = 0,
            _2_pixel = 1,
            _4_pixel = 2,
            _8_pixel = 3,
            _16_pixel = 4,
            _32_pixel = 5,
            _64_pixel = 6,
            _128_pixel = 7,
            _256_pixel = 8,
            _512_pixel = 9,
            _1024_pixel = 10,
        };
        enum __downsample_filter : uint8_t {
            Point_Sampled = 0,
            Box_Filter = 1,
            Blackman_Filter = 2,
            Lanczos_Filter = 3,
            Nuttall_Filter = 4,
            Blackman_Harris_Filter = 5,
            Blackman_Nuttall_Filter = 6,
            Flat_Top_Filter = 7,
            Extreme_Filter = 8,
        };
        struct __downsample_flags {
            uint16_t content;
            bool Sprites___Color_Bleed_in_Zero_Alpha_Regions() { return (content & 0b0000000000000001); }
            bool Pre_Multiply_Alpha__before_downsampling_() { return (content & 0b0000000000000010); }
            bool Post_Divide_Alpha__after_downsampling_() { return (content & 0b0000000000000100); }
            bool Height_Map___Convert_to_Bump_Map() { return (content & 0b0000000000001000); }
            bool Detail_Map___Fade_to_Gray() { return (content & 0b0000000000010000); }
            bool Signed____Unsigned_Scale_and_Bias() { return (content & 0b0000000000100000); }
            bool Illum_Map___Fade_to_Black() { return (content & 0b0000000001000000); }
            bool ZBump___Scale_by_height_and_renormalize() { return (content & 0b0000000010000000); }
            bool Cubemap___Fix_seams() { return (content & 0b0000000100000000); }
            bool Calculate_specular_power() { return (content & 0b0000001000000000); }
            bool Downsample_Bumps_in_Angular_Space() { return (content & 0b0000010000000000); }
            bool Standard_Orientation_of_Normals_in_Angular_Space_and_Renormalize() { return (content & 0b0000100000000000); }
            bool Generate_RGB_luminance_into_alpha_channel() { return (content & 0b0001000000000000); }
        };
        enum __swizzle_red : uint8_t {
            Default = 0,
            Source_Red_Channel = 1,
            Source_Green_Channel = 2,
            Source_Blue_Channel = 3,
            Source_Alpha_Channel = 4,
            Set_to_1_0 = 5,
            Set_to_0_0 = 6,
            Set_to_0_5 = 7,
            Random = 8,
        };
        enum __swizzle_green : uint8_t {
            Default = 0,
            Source_Red_Channel = 1,
            Source_Green_Channel = 2,
            Source_Blue_Channel = 3,
            Source_Alpha_Channel = 4,
            Set_to_1_0 = 5,
            Set_to_0_0 = 6,
            Set_to_0_5 = 7,
            Random = 8,
        };
        enum __swizzle_blue : uint8_t {
            Default = 0,
            Source_Red_Channel = 1,
            Source_Green_Channel = 2,
            Source_Blue_Channel = 3,
            Source_Alpha_Channel = 4,
            Set_to_1_0 = 5,
            Set_to_0_0 = 6,
            Set_to_0_5 = 7,
            Random = 8,
        };
        enum __swizzle_alpha : uint8_t {
            Default = 0,
            Source_Red_Channel = 1,
            Source_Green_Channel = 2,
            Source_Blue_Channel = 3,
            Source_Alpha_Channel = 4,
            Set_to_1_0 = 5,
            Set_to_0_0 = 6,
            Set_to_0_5 = 7,
            Random = 8,
        };
        enum __bitmap_format : uint32_t {
            Use_Default__defined_by_usage_ = 0,
            Best_Compressed_Color_Format = 1,
            Best_Uncompressed_Color_Format = 2,
            Best_Compressed_Bump_Format = 3,
            Best_Uncompressed_Bump_Format = 4,
            Best_Compressed_Monochrome_Format = 5,
            Best_Uncompressed_Monochrome_Format = 6,
            Best_Compressed_Monochrome_Format_without_alpha = 7,
            unused2_ = 8,
            unused3_ = 9,
            unused4_ = 10,
            unused5_ = 11,
            unused6_ = 12,
            ____Color_and_Alpha_formats____ = 13,
            bc1_unorm__a_k_a__DXT1___Compressed_Color___Color_Key_Alpha__DXT1__Compressed_Color___Color_Key_Alpha__ = 14,
            bc2_unorm__a_k_a__DXT3___Compressed_Color___4_bit_Alpha__DXT3__Compressed_Color___4_bit_Alpha__ = 15,
            bc3_unorm__a_k_a__DXT5___Compressed_Color___Compressed_8_bit_Alpha__DXT5__Compressed_Color___Compressed_8_bit_Alpha__ = 16,
            _24_bit_Color___8_bit_Alpha = 17,
            _8_bit_Monochrome___8_bit_Alpha = 18,
            ___Channel_Mask__3_bit_Color___1_bit_Alpha_ = 19,
            ___30_bit_Color___2_bit_Alpha = 20,
            ___48_bit_Color___16_bit_Alpha = 21,
            ___HALF_Color___Alpha = 22,
            ___FLOAT_Color___Alpha = 23,
            r8_unorm__8_bit_Intensity_replicated_to_RGBA__AY8__8_bit_Intensity_replicated_to_ARGB__ = 24,
            DEPRECATED_DXT3A__4_bit_Intensity_replicated_to_ARGB__DXT3A__4_bit_Intensity_replicated_to_ARGB__ = 25,
            bc4_unorm_rrrr__a_k_a__DXT5A___Compressed_Intensity_replicated_to_ARGB__bc4_unorm_000r__a_k_a__DXT5A___Compressed_Intensity_replicated_to_ARGB__ = 26,
            Compressed_Monochrome___Alpha = 27,
            b4g4r4a4__12_bit_color___4_bit_alpha__A4R4G4B4__12_bit_color___4_bit_alpha__ = 28,
            ____Color_only_formats____ = 29,
            _8_bit_Monochrome = 30,
            ___Compressed_24_bit_Color = 31,
            ___32_bit_Color__R11G11B10_ = 32,
            ___16_bit_Monochrome = 33,
            ___16_bit_Red___Green_Only = 34,
            ___16_bit_signed_RGBA____16_bit_signed_ARGB_ = 35,
            ___HALF_Red_Only = 36,
            ___FLOAT_Red_Only = 37,
            ___HALF_Red___Green_Only = 38,
            ___FLOAT_Red___Green_Only = 39,
            ___HALF_Monochrome = 40,
            DEPRECATED_Compressed_4_bit_Monochrome_Compressed_4_bit_Monochrome_ = 41,
            Compressed_Interpolated_Monochrome = 42,
            bc6h_uf16__HDR_RGB_unsigned_half_float__DXT5_red_ = 43,
            bc6h_sf16__HDR_RGB_signed_half_float__DXT5_green_ = 44,
            bc7_unorm__High_quality_bc3__DXT5_blue_ = 45,
            ____Alpha_only_formats____ = 46,
            DEPRECATED_DXT3A__4_bit_Alpha__DXT3A__4_bit_Alpha__ = 47,
            bc4_unorm_000r__a_k_a__DXT5A___8_bit_Compressed_Alpha__DXT5A__8_bit_Compressed_Alpha__ = 48,
            _8_bit_Alpha = 49,
            unused13_ = 50,
            unused14_ = 51,
            unused15_ = 52,
            ____Normal_map_formats____ = 53,
            bc5_snorm__a_k_a__DXN__Compressed_Normals__better__DXN_Compressed_Normals__better__ = 54,
            DEPRECATED_CTX1_Compressed_Normals__smaller__CTX1_Compressed_Normals__smaller__ = 55,
            _16_bit_Normals = 56,
            _32_bit_Normals = 57,
            _8_bit_4_channel_Vector = 58,
        };
        float source_gamma_0_0_to_use_xenon_curve__default_;
        __bitmap_curve bitmap_curve;
        __flags flags;
        __slicer slicer;
        __dicer_flags dicer_flags;
        __packer packer;
        __packer_flags packer_flags;
        __type type;
        int8_t mipmap_limit;
        __smallest_mip smallest_mip;
        __downsample_filter downsample_filter;
        int8_t filter_radius_bias;
        __downsample_flags downsample_flags;
        _s_rgbfloat sprite_background_color;
        __swizzle_red swizzle_red;
        __swizzle_green swizzle_green;
        __swizzle_blue swizzle_blue;
        __swizzle_alpha swizzle_alpha;
        __bitmap_format bitmap_format;
    };
    struct __manual_sequences_ {
        struct __sprites_ {
            int16_t bitmap_index_;
            uint8_t D[2];
            uint8_t GMLJPJIMC[4];
            float left_;
            float right_;
            float top_;
            float bottom_;
            _s_doublefloat registration_point_;
        };
        char name_[32];
        int16_t first_bitmap_index_;
        int16_t bitmap_count_;
        uint8_t OTXYKQ[16];
        _s_tagblock<__sprites_> sprites_;
    };
    struct __tight_bounds {
        _s_doublefloat uv;
    };
    struct __sequences_ {
        struct __sprites_ {
            int16_t bitmap_index_;
            uint8_t D[2];
            uint8_t GMLJPJIMC[4];
            float left_;
            float right_;
            float top_;
            float bottom_;
            _s_doublefloat registration_point_;
        };
        char name_[32];
        int16_t first_bitmap_index_;
        int16_t bitmap_count_;
        uint8_t OTXYKQ[16];
        _s_tagblock<__sprites_> sprites_;
    };
    struct __bitmaps_ {
        struct __more_flags_ {
            uint8_t content;
            bool xbox360_medium_resolution_offset_is_valid___DO_NOT_CHANGE() { return (content & 0b00000001); }
            bool xbox360_pitch__memory_spacing____DO_NOT_CHANGE() { return (content & 0b00000010); }
            bool xbox360_byte_order___DO_NOT_CHANGE() { return (content & 0b00000100); }
            bool xbox360_tiled_texture___DO_NOT_CHANGE() { return (content & 0b00001000); }
            bool xbox360_created_correctly__hack_for_bumpmaps____DO_NOT_CHANGE() { return (content & 0b00010000); }
            bool xbox360_high_resolution_offset_is_valid___DO_NOT_CHANGE() { return (content & 0b00100000); }
            bool xbox360_use_interleaved_textures___DO_NOT_CHANGE() { return (content & 0b01000000); }
            bool xbox360_use_on_demand_only___DO_NOT_CHANGE() { return (content & 0b10000000); }
        };
        enum __type__DO_NOT_CHANGE : uint8_t {
            _2D_texture = 0,
            _3D_texture = 1,
            cube_map = 2,
            array = 3,
        };
        enum __format__DO_NOT_CHANGE : uint16_t {
            a8_unorm__000A__a8_ = 0,
            r8_unorm_rrr1__RRR1__y8_ = 1,
            r8_unorm_rrrr__RRRR__ay8_ = 2,
            r8g8_unorm_rrrg__RRRG__r8g8_unorm_gggr__GGGR__ = 3,
            unused1 = 4,
            unused2 = 5,
            b5g6r5_unorm_r5g6b5_ = 6,
            unused3 = 7,
            b5g6r5a1_unorm_a1r5g5b5_ = 8,
            b4g4r4a4_unorm_a4r4g4b4_ = 9,
            b8g8r8x8_unorm_x8r8g8b8_ = 10,
            b8g8r8a8_unorm_a8r8g8b8_ = 11,
            unused4 = 12,
            DEPRECATED_dxt5_bias_alpha_dxt5_bias_alpha_ = 13,
            bc1_unorm__dxt1__dxt1_ = 14,
            bc2_unorm__dxt3__dxt3_ = 15,
            bc3_unorm__dxt5__dxt5_ = 16,
            DEPRECATED_a4r4g4b4_font_a4r4g4b4_font_ = 17,
            unused7 = 18,
            unused8 = 19,
            DEPRECATED_SOFTWARE_rgbfp32_software_rgbfp32_ = 20,
            unused9 = 21,
            r8g8_snorm__v8u8__v8u8_ = 22,
            DEPRECATED_g8b8_g8b8_ = 23,
            r32g32b32a32_float__abgrfp32__abgrfp32_ = 24,
            r16g16b16a16_float__abgrfp16__abgrfp16_ = 25,
            r16_float_rrr1__16f_mono__16f_mono_ = 26,
            r16_float_r000__16f_red__16f_red_ = 27,
            r8g8b8a8_snorm__q8w8v8u8__q8w8v8u8_ = 28,
            r10g10b10a2_unorm__a2r10g10b10__a2r10g10b10_ = 29,
            r16g16b16a16_unorm__a16b16g16r16__a16b16g16r16_ = 30,
            r16g16_snorm__v16u16__v16u16_ = 31,
            r16_unorm_rrr0__L16__l16_ = 32,
            r16g16_unorm__r16g16__r16g16_ = 33,
            r16g16b16a16_snorm__signedr16g16b16a16__signedr16g16b16a16_ = 34,
            DEPRECATED_dxt3a_dxt3a_ = 35,
            bc4_unorm_rrrr__dxt5a__bc4_unorm__dxt5a__ = 36,
            bc4_snorm_rrrr = 37,
            DEPRECATED_dxt3a_1111_dxt3a_1111_ = 38,
            bc5_snorm__dxn__dxn_ = 39,
            DEPRECATED_ctx1_ctx1_ = 40,
            DEPRECATED_dxt3a_alpha_only_dxt3a_alpha_ = 41,
            DEPRECATED_dxt3a_monochrome_only_dxt3a_mono_ = 42,
            bc4_unorm_000r__dxt5a_alpha__dxt5a_alpha_ = 43,
            bc4_unorm_rrr1__dxt5a_mono__dxt5a_mono_ = 44,
            bc5_unorm_rrrg__dxn_mono_alpha__dxn_mono_alpha_ = 45,
            bc5_snorm_rrrg__dxn_mono_alpha_signed_ = 46,
            bc6h_uf16__dxt5_red_ = 47,
            bc6h_sf16__dxt5_green_ = 48,
            bc7_unorm__dxt5_blue_ = 49,
            d24_unorm_s8_uint__depth_24__depth_24_ = 50,
            r11g11b10_float = 51,
        };
        struct __flags_ {
            uint8_t content;
            bool power_of_two_dimensions__DO_NOT_CHANGE() { return (content & 0b00000001); }
            bool compressed__DO_NOT_CHANGE() { return (content & 0b00000010); }
            bool swap_axes__DO_NOT_CHANGE() { return (content & 0b00000100); }
            bool mutable_at_runtime_eg_for_forge_lightmapper_or_other_runtime_processes_that_edit_bitmaps() { return (content & 0b00001000); }
        };
        enum __curve_how_to_convert_from_pixel_value_to_linear : uint8_t {
            unknown = 0,
            xRGB__gamma_about_2_0__SRGB__gamma_2_2__ = 1,
            gamma_2_0 = 2,
            linear = 3,
            offset_log = 4,
            sRGB__gamma_2_2_ = 5,
            Rec709__gamma_2_2_ = 6,
        };
        struct __bitmap_resource_handle_ {
        };
        int16_t width__pixels_DO_NOT_CHANGE;
        int16_t height__pixels_DO_NOT_CHANGE;
        int8_t depth__pixels_DO_NOT_CHANGE;
        __more_flags_ more_flags_;
        __type__DO_NOT_CHANGE type__DO_NOT_CHANGE;
        int8_t four_times_log2_size__DO_NOT_CHANGE;
        __format__DO_NOT_CHANGE format__DO_NOT_CHANGE;
        __flags_ flags_;
        int8_t exponent_bias;
        _s_point2d registration_point_the__center__of_the_bitmap___i_e__for_particles;
        int8_t mipmap_count__DO_NOT_CHANGE__not_counting_the_highest_resolution_;
        __curve_how_to_convert_from_pixel_value_to_linear curve_how_to_convert_from_pixel_value_to_linear;
        uint8_t unused[1];
        int8_t interleaved_texture_index;
        float streaming_scale;
        _s_resource<__bitmap_resource_handle_> bitmap_resource_handle_;
    };
    struct __xenon_bitmaps_ {
        struct __more_flags_ {
            uint8_t content;
            bool xbox360_medium_resolution_offset_is_valid___DO_NOT_CHANGE() { return (content & 0b00000001); }
            bool xbox360_pitch__memory_spacing____DO_NOT_CHANGE() { return (content & 0b00000010); }
            bool xbox360_byte_order___DO_NOT_CHANGE() { return (content & 0b00000100); }
            bool xbox360_tiled_texture___DO_NOT_CHANGE() { return (content & 0b00001000); }
            bool xbox360_created_correctly__hack_for_bumpmaps____DO_NOT_CHANGE() { return (content & 0b00010000); }
            bool xbox360_high_resolution_offset_is_valid___DO_NOT_CHANGE() { return (content & 0b00100000); }
            bool xbox360_use_interleaved_textures___DO_NOT_CHANGE() { return (content & 0b01000000); }
            bool xbox360_use_on_demand_only___DO_NOT_CHANGE() { return (content & 0b10000000); }
        };
        enum __type__DO_NOT_CHANGE : uint8_t {
            _2D_texture = 0,
            _3D_texture = 1,
            cube_map = 2,
            array = 3,
        };
        enum __format__DO_NOT_CHANGE : uint16_t {
            a8_unorm__000A__a8_ = 0,
            r8_unorm_rrr1__RRR1__y8_ = 1,
            r8_unorm_rrrr__RRRR__ay8_ = 2,
            r8g8_unorm_rrrg__RRRG__r8g8_unorm_gggr__GGGR__ = 3,
            unused1 = 4,
            unused2 = 5,
            b5g6r5_unorm_r5g6b5_ = 6,
            unused3 = 7,
            b5g6r5a1_unorm_a1r5g5b5_ = 8,
            b4g4r4a4_unorm_a4r4g4b4_ = 9,
            b8g8r8x8_unorm_x8r8g8b8_ = 10,
            b8g8r8a8_unorm_a8r8g8b8_ = 11,
            unused4 = 12,
            DEPRECATED_dxt5_bias_alpha_dxt5_bias_alpha_ = 13,
            bc1_unorm__dxt1__dxt1_ = 14,
            bc2_unorm__dxt3__dxt3_ = 15,
            bc3_unorm__dxt5__dxt5_ = 16,
            DEPRECATED_a4r4g4b4_font_a4r4g4b4_font_ = 17,
            unused7 = 18,
            unused8 = 19,
            DEPRECATED_SOFTWARE_rgbfp32_software_rgbfp32_ = 20,
            unused9 = 21,
            r8g8_snorm__v8u8__v8u8_ = 22,
            DEPRECATED_g8b8_g8b8_ = 23,
            r32g32b32a32_float__abgrfp32__abgrfp32_ = 24,
            r16g16b16a16_float__abgrfp16__abgrfp16_ = 25,
            r16_float_rrr1__16f_mono__16f_mono_ = 26,
            r16_float_r000__16f_red__16f_red_ = 27,
            r8g8b8a8_snorm__q8w8v8u8__q8w8v8u8_ = 28,
            r10g10b10a2_unorm__a2r10g10b10__a2r10g10b10_ = 29,
            r16g16b16a16_unorm__a16b16g16r16__a16b16g16r16_ = 30,
            r16g16_snorm__v16u16__v16u16_ = 31,
            r16_unorm_rrr0__L16__l16_ = 32,
            r16g16_unorm__r16g16__r16g16_ = 33,
            r16g16b16a16_snorm__signedr16g16b16a16__signedr16g16b16a16_ = 34,
            DEPRECATED_dxt3a_dxt3a_ = 35,
            bc4_unorm_rrrr__dxt5a__bc4_unorm__dxt5a__ = 36,
            bc4_snorm_rrrr = 37,
            DEPRECATED_dxt3a_1111_dxt3a_1111_ = 38,
            bc5_snorm__dxn__dxn_ = 39,
            DEPRECATED_ctx1_ctx1_ = 40,
            DEPRECATED_dxt3a_alpha_only_dxt3a_alpha_ = 41,
            DEPRECATED_dxt3a_monochrome_only_dxt3a_mono_ = 42,
            bc4_unorm_000r__dxt5a_alpha__dxt5a_alpha_ = 43,
            bc4_unorm_rrr1__dxt5a_mono__dxt5a_mono_ = 44,
            bc5_unorm_rrrg__dxn_mono_alpha__dxn_mono_alpha_ = 45,
            bc5_snorm_rrrg__dxn_mono_alpha_signed_ = 46,
            bc6h_uf16__dxt5_red_ = 47,
            bc6h_sf16__dxt5_green_ = 48,
            bc7_unorm__dxt5_blue_ = 49,
            d24_unorm_s8_uint__depth_24__depth_24_ = 50,
            r11g11b10_float = 51,
        };
        struct __flags_ {
            uint8_t content;
            bool power_of_two_dimensions__DO_NOT_CHANGE() { return (content & 0b00000001); }
            bool compressed__DO_NOT_CHANGE() { return (content & 0b00000010); }
            bool swap_axes__DO_NOT_CHANGE() { return (content & 0b00000100); }
            bool mutable_at_runtime_eg_for_forge_lightmapper_or_other_runtime_processes_that_edit_bitmaps() { return (content & 0b00001000); }
        };
        enum __curve_how_to_convert_from_pixel_value_to_linear : uint8_t {
            unknown = 0,
            xRGB__gamma_about_2_0__SRGB__gamma_2_2__ = 1,
            gamma_2_0 = 2,
            linear = 3,
            offset_log = 4,
            sRGB__gamma_2_2_ = 5,
            Rec709__gamma_2_2_ = 6,
        };
        struct __bitmap_resource_handle_ {
        };
        int16_t width__pixels_DO_NOT_CHANGE;
        int16_t height__pixels_DO_NOT_CHANGE;
        int8_t depth__pixels_DO_NOT_CHANGE;
        __more_flags_ more_flags_;
        __type__DO_NOT_CHANGE type__DO_NOT_CHANGE;
        int8_t four_times_log2_size__DO_NOT_CHANGE;
        __format__DO_NOT_CHANGE format__DO_NOT_CHANGE;
        __flags_ flags_;
        int8_t exponent_bias;
        _s_point2d registration_point_the__center__of_the_bitmap___i_e__for_particles;
        int8_t mipmap_count__DO_NOT_CHANGE__not_counting_the_highest_resolution_;
        __curve_how_to_convert_from_pixel_value_to_linear curve_how_to_convert_from_pixel_value_to_linear;
        uint8_t unused[1];
        int8_t interleaved_texture_index;
        float streaming_scale;
        _s_resource<__bitmap_resource_handle_> bitmap_resource_handle_;
    };
    int64_t vtable_space___;
    __internal_struct internal_struct;
    __Usage_choose_how_you_are_using_this_bitmap Usage_choose_how_you_are_using_this_bitmap;
    __Flags Flags;
    int16_t sprite_spacing_number_of_pixels_between_adjacent_sprites__0_uses_default__negative_numbers_set_no_spacing_;
    uint8_t pad_spsp[2];
    float bump_map_height_repeats_the_apparent_height_of_the_bump_map_above_the_triangle_it_is_textured_onto__in_texture_repeats__i_e___1_0_would_be_as_high_as_the_texture_is_wide_;
    float fade_factor__0_1__used_by_detail_maps_and_illum_maps___0_means_fade_by_last_mipmap__1_means_fade_by_first_mipmap;
    float blur_pixels_how_much_to_blur_the_input_image;
    float mip_map_blur_pixels_how_much_to_blur_as_each_mip_level_is_being_downsampled;
    float specular_power_bias_Adjusts_sharpness_of_resulting_cubemap;
    float base_MIP_bias_degrees_Zero_indicates_that_512x512_is_our_infinite_detail_MIP;
    __curve_mode_automatic_chooses_FAST_if_your_bitmap_is_bright__and_PRETTY_if_your_bitmap_has_dark_bits curve_mode_automatic_chooses_FAST_if_your_bitmap_is_bright__and_PRETTY_if_your_bitmap_has_dark_bits;
    int8_t max_mipmap_level_0___use_default_defined_by_usage;
    int16_t max_resolution_0___do_not_downsample_source_image;
    int16_t atlas_index_into_global_atlas_if_the_texture_is_missing_its_required_resources_and_has_been_atlased;
    __force_bitmap_format_overrides_the_format_defined_by_usage force_bitmap_format_overrides_the_format_defined_by_usage;
    float tight_bounds_threshold__0_0___1_0__This_is_the_level_cutoff_for_tight_bounds___0_0_is_monochrome_black__1_0_is_monochrome_white;
    _s_tagblock<__usage_override> usage_override;
    _s_tagblock<__manual_sequences_> manual_sequences_;
    _s_tagblock<__tight_bounds> tight_bounds;
    _s_data source_data_;
    uint64_t source_checksum_;
    _s_data processed_pixel_data_;
    _s_tagblock<__sequences_> sequences_;
    _s_tagblock<__bitmaps_> bitmaps_;
    _s_data xenon_processed_pixel_data_;
    _s_tagblock<__xenon_bitmaps_> xenon_bitmaps_;
    uint8_t alignment[4];
};
#pragma pack(pop)