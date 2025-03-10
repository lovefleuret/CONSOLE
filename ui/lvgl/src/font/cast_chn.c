/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --no-compress --font SourceHanSansCN_Light_2.otf --symbols 2. 当iPhone显示弹出窗口时，请点击"信任”。
 --format lvgl -o cast_chn.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef CAST_CHN
#define CAST_CHN 1
#endif

#if CAST_CHN

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+000A "\n" */
    0x0,

    /* U+0020 " " */
    0x0,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+002E "." */
    0xf0,

    /* U+0032 "2" */
    0x38, 0xc4, 0x2, 0x2, 0x2, 0x2, 0x4, 0x4,
    0x8, 0x10, 0x20, 0x40, 0xff,

    /* U+0050 "P" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80,

    /* U+0065 "e" */
    0x3c, 0x62, 0xc1, 0x81, 0xff, 0x80, 0x80, 0xc0,
    0x60, 0x3e,

    /* U+0068 "h" */
    0x81, 0x2, 0x4, 0xb, 0xd8, 0xe0, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x30, 0x40,

    /* U+0069 "i" */
    0xc2, 0xaa, 0xaa, 0x80,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x4,

    /* U+006F "o" */
    0x3c, 0x31, 0x90, 0x50, 0x18, 0xc, 0x6, 0x2,
    0x82, 0x63, 0x1f, 0x0,

    /* U+201D "”" */
    0x6d, 0xb2, 0x51, 0x8,

    /* U+3002 "。" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0,

    /* U+4EFB "任" */
    0x4, 0x0, 0x2, 0x3, 0x82, 0x7e, 0x1, 0x42,
    0x1, 0x1, 0x1, 0x80, 0x81, 0x40, 0x41, 0xa0,
    0x20, 0x97, 0xff, 0x88, 0x8, 0x4, 0x4, 0x2,
    0x2, 0x1, 0x1, 0x0, 0x80, 0x80, 0x40, 0x40,
    0x27, 0xff,

    /* U+4FE1 "信" */
    0x8, 0x40, 0x10, 0x20, 0x10, 0x20, 0x27, 0xff,
    0x20, 0x0, 0x63, 0xfe, 0xa0, 0x0, 0xa0, 0x0,
    0x23, 0xfe, 0x20, 0x0, 0x20, 0x0, 0x23, 0xfe,
    0x22, 0x2, 0x22, 0x2, 0x22, 0x2, 0x23, 0xfe,

    /* U+51FA "出" */
    0x2, 0x0, 0x8, 0x4, 0x20, 0x90, 0x82, 0x42,
    0x9, 0x8, 0x24, 0x20, 0x9f, 0xfe, 0x2, 0x2,
    0x8, 0x18, 0x20, 0x60, 0x81, 0x82, 0x6, 0x8,
    0x1f, 0xff, 0xc0, 0x1,

    /* U+51FB "击" */
    0x1, 0x0, 0x2, 0x0, 0x4, 0x3, 0xff, 0xe0,
    0x10, 0x0, 0x20, 0x0, 0x40, 0x7f, 0xff, 0x1,
    0x0, 0x82, 0x11, 0x4, 0x22, 0x8, 0x44, 0x10,
    0x88, 0x21, 0x1f, 0xfe, 0x0, 0x4,

    /* U+53E3 "口" */
    0xff, 0xfc, 0x0, 0x60, 0x3, 0x0, 0x18, 0x0,
    0xc0, 0x6, 0x0, 0x30, 0x1, 0x80, 0xc, 0x0,
    0x60, 0x3, 0xff, 0xf8, 0x0, 0xc0, 0x4,

    /* U+5F39 "弹" */
    0x1, 0x4, 0xf8, 0x84, 0x8, 0x88, 0x8, 0x18,
    0xb, 0xfe, 0xfa, 0x22, 0x82, 0x22, 0x83, 0xfe,
    0x82, 0x22, 0x7b, 0xfe, 0x8, 0x20, 0x8, 0x20,
    0xf, 0xff, 0x8, 0x20, 0x8, 0x20, 0xf0, 0x20,

    /* U+5F53 "当" */
    0x82, 0xc, 0x10, 0x50, 0x84, 0x44, 0x22, 0x22,
    0x1, 0x3, 0xff, 0xe0, 0x1, 0x0, 0x8, 0x0,
    0x5f, 0xfe, 0x0, 0x10, 0x0, 0x80, 0x4, 0x0,
    0x3f, 0xff,

    /* U+65F6 "时" */
    0x0, 0x9, 0xf0, 0x12, 0x20, 0x24, 0x40, 0x48,
    0xbf, 0xf1, 0x1, 0x22, 0x2, 0x7c, 0x84, 0x88,
    0x89, 0x10, 0x92, 0x21, 0x24, 0x40, 0x4f, 0x80,
    0x90, 0x1, 0x0, 0x2, 0x0, 0x7c,

    /* U+663E "显" */
    0x3f, 0xfc, 0x20, 0x4, 0x20, 0x4, 0x3f, 0xfc,
    0x20, 0x4, 0x20, 0x4, 0x3f, 0xfc, 0x0, 0x0,
    0x4, 0x40, 0x24, 0x44, 0x24, 0x44, 0x14, 0x48,
    0x4, 0x50, 0x4, 0x40, 0xff, 0xff,

    /* U+70B9 "点" */
    0x0, 0x80, 0x0, 0x80, 0x0, 0x80, 0x0, 0xfe,
    0x0, 0x80, 0x0, 0x80, 0x3f, 0xfc, 0x20, 0x4,
    0x20, 0x4, 0x20, 0x4, 0x20, 0x4, 0x3f, 0xfc,
    0x0, 0x0, 0x20, 0x4, 0x22, 0x42, 0x42, 0x22,
    0x82, 0x21,

    /* U+793A "示" */
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0x1, 0x0, 0x1, 0x0,
    0x11, 0x8, 0x11, 0x4, 0x21, 0x4, 0x41, 0x2,
    0x81, 0x3, 0x1, 0x0, 0xf, 0x0,

    /* U+7A97 "窗" */
    0x1, 0x0, 0x2, 0x3, 0xff, 0xfc, 0x0, 0x18,
    0xc3, 0x26, 0x21, 0x90, 0x80, 0x9f, 0xfe, 0x20,
    0x4, 0x44, 0x8, 0x9f, 0x91, 0x41, 0x22, 0x34,
    0x44, 0x18, 0x88, 0xc9, 0x16, 0x2, 0x3f, 0xfc,

    /* U+8BF7 "请" */
    0x0, 0x20, 0x23, 0xfe, 0x10, 0x20, 0x8, 0x20,
    0x3, 0xfe, 0x0, 0x20, 0xf7, 0xff, 0x10, 0x0,
    0x13, 0xfc, 0x12, 0x4, 0x13, 0xfc, 0x12, 0x4,
    0x12, 0x4, 0x17, 0xfc, 0x1a, 0x4, 0x2, 0x1c,

    /* U+FF0C "，" */
    0x6c, 0x9c, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 120, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 4, .adv_w = 72, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 154, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 176, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 155, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 170, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 74, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 171, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 171, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 288, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 83, .adv_w = 288, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 88, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 122, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 154, .adv_w = 288, .box_w = 14, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 182, .adv_w = 288, .box_w = 15, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 212, .adv_w = 288, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 235, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 267, .adv_w = 288, .box_w = 13, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 293, .adv_w = 288, .box_w = 15, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 323, .adv_w = 288, .box_w = 16, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 353, .adv_w = 288, .box_w = 16, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 387, .adv_w = 288, .box_w = 16, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 417, .adv_w = 288, .box_w = 15, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 449, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 481, .adv_w = 288, .box_w = 3, .box_h = 6, .ofs_x = 2, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x16, 0x18, 0x24, 0x28, 0x46, 0x5b, 0x5e,
    0x5f, 0x64, 0x65, 0x2013, 0x2ff8, 0x4ef1, 0x4fd7, 0x51f0,
    0x51f1, 0x53d9, 0x5f2f, 0x5f49, 0x65ec, 0x6634, 0x70af, 0x7930,
    0x7a8d, 0x8bed, 0xff02
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 10, .range_length = 65283, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 27, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 4,
    3, 7,
    3, 11,
    4, 3,
    4, 7,
    4, 11,
    6, 4,
    6, 7,
    6, 11,
    11, 3,
    11, 4
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -34, -11, -11, -26, -4, -4, -33, -8,
    -8, -11, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 11,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t cast_chn = {
#else
lv_font_t cast_chn = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if CAST_CHN*/

