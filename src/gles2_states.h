/* This file defines a partial cached gles states */
#ifndef GPUPROCESS_GLES2_STATE_H
#define GPUPROCESS_GLES2_STATE_H

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "types_private.h"

#define NUM_EMBEDDED 32

/* these are client state */
typedef struct vertex_attrib
{
    GLuint        index;
    GLint         array_buffer_binding;   /* initial is 0 */
    GLboolean     array_enabled;          /* initial GL_FALSE */
    GLint         size;                   /* initial 4 */
    GLint         stride;                 /* initial 0 */
    GLenum        type;                   /* initial GL_FLOAT */
    GLvoid        *pointer;               /* initial is 0 */
    GLboolean     array_normalized;       /* initial is GL_FALSE */
    GLfloat       current_attrib[4];      /* initial is (0, 0, 0, 1) */
    char          *data;
} vertex_attrib_t;

typedef struct vertex_attrib_list
{
    int                 count;          /* initial 0 */
    vertex_attrib_t     embedded_attribs[NUM_EMBEDDED];
    vertex_attrib_t     *attribs;
} vertex_attrib_list_t;

typedef struct v_program_status {
    GLboolean    delete_status;
    GLboolean    link_status;
    GLboolean    validate_status;
    GLint        info_log_length;                 /* initial 0 */
    GLint        attached_shaders;
    GLint        active_attributes;
    GLint        active_attribute_max_length;     /* longest name + NULL */
    GLint        active_uniforms;
    GLint        active_uniform_max_length;       /* longest name + NULL */
} v_program_status_t;

/* this struct for attribute */
typedef struct v_program_attrib {
    GLuint        location;
    GLuint        index;
    GLchar        *name;
} v_program_attrib_t;

typedef struct v_program_attrib_list {
    int                 count;
    v_program_attrib_t  *attribs;
} v_program_attrib_list_t;

typedef struct v_program_uniform {
    GLuint        location;
    GLchar        *name;
    GLchar        *value;
    GLint         num_bytes;        /* number of bytes occupied by value */
} v_program_uniform_t;

typedef struct v_program_uniform_list {
    int                        count;
    v_program_uniform_t *uniforms;
} v_program_uniform_list_t;

typedef struct v_program {
    GLuint                      program;
    v_program_status_t          status;
    v_program_attrib_list_t     attribs;
    v_program_uniform_list_t    uniforms;
} v_program_t;

typedef struct gl_state {
    GLenum                  error;             /* initial is GL_NO_ERROR */
    bool                    need_get_error;
    link_list_t           *programs;         /* initial is NULL */
    vertex_attrib_list_t  vertex_attribs;    /* client states */

/* GL states from glGet () */
    /* used */
    GLint         active_texture;              /* initial GL_TEXTURE0 */
    GLfloat       aliased_line_width_range[2]; /* must include 1 */
    GLfloat       aliased_point_size_range[2]; /* must include 1 */
    GLint         bits[4];                     /* alpha, red, green and
                                                * blue bits 
                                                */        
    /* used */
    GLint         array_buffer_binding;         /* initial 0 */
    /* used */
    GLboolean     blend;                        /* initial GL_FALSE */
    /* used */
    GLfloat       blend_color[4];               /* initial 0, 0, 0, 0 */
    /*used all here */
    GLfloat       blend_dst[4];                 /* RGBA, initial GL_ZERO */
    GLfloat       blend_src[4];                 /* RGBA, initial GL_ONE */
    /* used */
    GLint         blend_equation[2];            /* 1 rgb, 2 alpha, initial
                                                 * GL_FUNC_ADD
                                                 */
    /* used */
    GLfloat       color_clear_value[4];         /* initial 0.0 */
    /* used */
    GLboolean     color_writemask[4];           /* initial all GL_TRUE */

    /* XXX: save GL_COMPRESSED_TEXTURE_FORMATS ? */
    /* used */
    GLboolean     cull_face;                    /* initial GL_FALSE */
    /* used */
    GLint         cull_face_mode;               /* initial GL_BACK */

    /* used */
    GLint         current_program;              /* initial 0 */

    GLint         depth_bits;
    /* used */
    GLfloat       depth_clear_value;            /* initial 1 */
    /* used */
    GLint         depth_func;                   /* initial GL_LESS */
    /* used */
    GLfloat       depth_range[2];               /* initial 0, 1 */
    /* used */
    GLboolean     depth_test;                   /* initial GL_FALSE */
    /* used */
    GLboolean     depth_writemask;              /* initial GL_TRUE */

    /* used */
    GLboolean     dither;                       /* intitial GL_TRUE */
    /* used */
    GLint         element_array_buffer_binding; /* initial 0 */

    /* used */
    GLint         framebuffer_binding;          /* initial 0 */

    /* used */
    GLint         front_face;                   /* initial GL_CCW */

    /* used */
    GLint         generate_mipmap_hint;         /* initial GL_DONT_CARE */

    GLint         implementation_color_read_format;/* GL_UNSIGNED_BYTE is 
                                                    * always allowed 
                                                    */
    GLint         implementation_color_read_type;  /* GL_RGBA is always 
                                                    * allowed 
                                                    */
    /* used */
    GLfloat       line_width;                    /* initial 1 */

    /* used all */
    GLint         max_combined_texture_image_units; /* at least 8 */
    bool          max_combined_texture_image_units_queried;
    GLint         max_cube_map_texture_size;        /* at least 16 */
    bool          max_cube_map_texture_size_queried;
    GLint         max_fragment_uniform_vectors;     /* at least 16 */
    bool          max_fragment_uniform_vectors_queried;
    GLint         max_renderbuffer_size;            /* at least 1 */
    bool          max_renderbuffer_size_queried;
    GLint         max_texture_image_units;          /* at least 8 */
    bool          max_texture_image_units_queried;
    GLint         max_texture_size;                 /* at least 64 */
    bool          max_texture_size_queried;
    GLint         max_varying_vectors;              /* at least 8 */
    bool          max_varying_vectors_queried;
    GLint         max_vertex_uniform_vectors;       /* at least 128 */
    bool          max_vertex_uniform_vectors_queried;
    /* used all */
    bool          max_vertex_attribs_queried;       /*  false */
    GLint         max_vertex_attribs;               /* at least 8 */
    GLint         max_vertex_texture_image_units;   /* may be 0 */
    bool          max_vertex_texture_image_units_queried;
    GLint         max_viewport_dims;                /* as large as visible */
    /* used all */
    GLint         num_compressed_texture_formats;   /* min is 0 */
    GLint         num_shader_binary_formats;        /* min is 0 */
    /* used all */
    GLint         pack_alignment;                   /* initial is 4 */
    GLint         unpack_alignment;                 /* initial is 4 */
    /* used */
    GLfloat       polygon_offset_factor;            /* initial 0 */
    /* used */
    GLboolean     polygon_offset_fill;              /* initial GL_FALSE */
    /* used */
    GLfloat       polygon_offset_units;             /* initial is 0 */   

    GLint         renderbuffer_binding;             /* initial 0 */
    
    /* used */
    GLboolean     sample_alpha_to_coverage;         /* initial GL_FALSE */
    GLint         sample_buffers;        
    /* used */
    GLboolean     sample_coverage;                  /* initial GL_FALSE */
    /* used */
    GLboolean     sample_coverage_invert;           /* initial GL_FALSE */
    GLfloat       sample_coverage_value;            /* positive float */

    GLint         samples;
    /* used */
    GLint         scissor_box[4];                   /* initial (0, 0, 0, 0) */
    /* used */
    GLboolean     scissor_test;                     /* initial GL_FALSE */
    
    GLint         shader_binary_formats;
    /* used */        
    GLboolean     shader_compiler;                

    /* used all */
    GLint         stencil_back_fail;                /* initial GL_KEEP */
    GLint         stencil_back_func;                /* initial GL_ALWAYS */
    GLint         stencil_back_pass_depth_fail;     /* initial GL_KEEP */
    GLint         stencil_back_pass_depth_pass;     /* initial GL_KEEP */
    GLint         stencil_back_ref;                 /* initial is 0 */
    GLint         stencil_back_value_mask;          /* initial 0xffffffff */
    GLint         stencil_back_writemask;           /* initial 0xffffffff */

    GLint         stencil_bits;
    /* used */
    GLint         stencil_clear_value;               /* initial 0 */
    GLint         stencil_fail;                      /* initial GL_KEEP */
    GLint         stencil_func;                      /* initial GL_ALWAYS */
    GLint         stencil_pass_depth_fail;           /* initial GL_KEEP */
    GLint         stencil_pass_depth_pass;           /* initial GL_KEEP */
    GLint         stencil_ref;                       /* initial is 0 */
    /* used */
    GLboolean     stencil_test;                      /* intitial GL_FALSE */
    GLint         stencil_value_mask;                /* initial 0xffffffff */
    GLint         stencil_writemask;                 /* initial 0xffffffff */
    
    GLint         subpixel_bits;                     /* at least 4 */
    /*used */
    GLint         texture_binding[2];                /* 2D, cube_map, initial 0 */
    /* used */
    GLint         viewport[4];                       /* initial (0, 0, 0, 0) */
    
    /* glGetString () */
    GLubyte       vendor[256];
    GLubyte       renderer[256];
    GLubyte       extensions[4096];                  /* too large or short? */
    GLubyte       shading_language_version[128];

    /* glGetTextureParameter() */
    /* used */
    GLint         texture_mag_filter[32][3];        /* initial GL_LINEAR */
    GLint         texture_min_filter[32][3];        /* initial GL_NEAREST_MIPMAP_LINEAR */
    GLint         texture_wrap_s[32][3];            /* initial GL_REPEAT */
    GLint         texture_wrap_t[32][3];            /* initial GL_REPEAT */

    /* glGetBufferParameter() */
    GLint         buffer_size[2];                   /* initial 0 */        
    GLint         buffer_usage[2];                  /* initial GL_STATIC_DRAW */

    /* glGetFramebufferAttachmentParameter() */
    /* XXX: do we need to cache them? */
    
    /* glGetRenderbufferParameter() */
    /* XXX: do we need to cache them ? */

    /* used */
    GLint        texture_binding_3d;
    GLint        max_3d_texture_size;
    bool         max_3d_texture_size_queried;
    /* used */
    GLint        texture_3d_wrap_r[32];         /* initial GL_REPEAT */
    GLint        vertex_array_binding;
    GLint        draw_framebuffer_binding;                /* initial 0 ? */
    GLint        read_framebuffer_binding;                /* initial 0 ? */

    GLint        max_samples;
    bool         max_samples_queried;

    GLint        texture_max_level;

} gles2_state_t;

#endif /* GPUPROCESS_GLES2_STATE_H */
