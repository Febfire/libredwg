
// libredwg API example
// This is the only file an user of the API needs to include

#ifndef _API_H_
#define _API_H_

typedef struct dwg_point_3d
{
	double x;
	double y;
	double z;
} dwg_point_3d;

typedef struct dwg_point_2d
{
	double x;
	double y;
} dwg_point_2d;

typedef struct error
{
  int evalue;
} error;

// Extract All Entities of a specific type from a BLOCK
#define GET_DWG_ENTITY(token) \
Dwg_Entity_##token ** \
 dwg_get_##token (Dwg_Object_Ref * ref) \
{ \
  int x=0,counts=0; \
  Dwg_Object * obj; \
  Dwg_Object_BLOCK_HEADER * hdr; \
  hdr = ref->obj->tio.object->tio.BLOCK_HEADER; \
  obj = get_first_owned_object(ref->obj, hdr); \
  while(obj) \
    { \
    if(obj->type== DWG_TYPE_##token) \
      { \
        counts++; \
      } \
    obj = get_next_owned_object(ref->obj, obj, hdr); \
    } \
  Dwg_Entity_##token ** ret_##token = (Dwg_Entity_##token **)malloc ( \
  counts * sizeof ( Dwg_Entity_##token *)); \
  obj = get_first_owned_object(ref->obj, hdr); \
  while(obj) \
   { \
     if(obj->type==DWG_TYPE_##token) \
      { \
        ret_##token[x] = obj->tio.entity->tio.token; \
        x++; \
      } \
    obj = get_next_owned_object(ref->obj, obj, hdr); \
  } \
  return ret_##token; \
}

// Cast a Dwg_Object to Entity
#define CAST_OBJECT(token) \
Dwg_Entity_##token * \
dwg_object_to_##token(Dwg_Object *obj) \
{ \
  Dwg_Entity_##token *ret_obj; \
  if(obj != 0 && obj->type == DWG_TYPE_##token) \
    { \
      ret_obj = obj->tio.entity->tio.token; \
    } \
  return ret_obj; \
}

//------------------------------------------------------------------------------
typedef struct _dwg_entity_CIRCLE                 dwg_ent_circle;
typedef struct _dwg_entity_LINE                   dwg_ent_line;
typedef struct _dwg_entity_ARC                    dwg_ent_arc;
typedef struct _dwg_entity_ELLIPSE                dwg_ent_ellipse;
typedef struct _dwg_entity_TEXT                   dwg_ent_text;
typedef struct _dwg_entity_POINT                  dwg_ent_point;
typedef struct _dwg_entity_ATTRIB                 dwg_ent_attrib;
typedef struct _dwg_entity_ATTDEF                 dwg_ent_attdef;
typedef struct _dwg_entity_SOLID                  dwg_ent_solid;
typedef struct _dwg_entity_TRACE                  dwg_ent_trace;
typedef struct _dwg_entity_INSERT                 dwg_ent_insert;
typedef struct _dwg_entity_MINSERT                dwg_ent_minsert;
typedef struct _dwg_entity_BLOCK                  dwg_ent_block;
typedef struct _dwg_entity_RAY                    dwg_ent_ray, 
                                                  dwg_ent_xline;
typedef struct _dwg_entity_VERTEX_3D              dwg_ent_vertex_3d, 
                                                  dwg_ent_vertex_mesh,
                                                  dwg_ent_vertex_pface;
typedef struct _dwg_entity_VERTEX_2D              dwg_ent_vertex_2d;
typedef struct _dwg_entity_DIMENSION_ORDINATE     dwg_ent_dim_ordinate;
typedef struct _dwg_entity_DIMENSION_LINEAR       dwg_ent_dim_linear;
typedef struct _dwg_entity_DIMENSION_ALIGNED      dwg_ent_dim_aligned;
typedef struct _dwg_entity_DIMENSION_ANG3PT       dwg_ent_dim_ang3pt;
typedef struct _dwg_entity_DIMENSION_ANG2LN       dwg_ent_dim_ang2ln;
typedef struct _dwg_entity_DIMENSION_RADIUS       dwg_ent_dim_radius;
typedef struct _dwg_entity_DIMENSION_DIAMETER     dwg_ent_dim_diameter;
typedef struct _dwg_entity_LEADER                 dwg_ent_leader;
typedef struct _dwg_entity_SHAPE                  dwg_ent_shape;
typedef struct _dwg_entity_MTEXT                  dwg_ent_mtext;
typedef struct _dwg_entity_TOLERANCE              dwg_ent_tolerance;
typedef struct _dwg_entity_ENDBLK                 dwg_ent_endblk;
typedef struct _dwg_entity_SEQEND                 dwg_ent_seqend;
//-------------------------------------------------------------------------------

typedef struct _dwg_object_LAYER             dwg_obj_layer;
typedef struct _dwg_object_BLOCK_HEADER      dwg_obj_block_header;
typedef struct _dwg_object_BLOCK_CONTROL     dwg_obj_block_control;
typedef struct _dwg_object_MLINESTYLE        dwg_obj_mlinestyle;
typedef struct _dwg_object_APPID             dwg_obj_appid;
typedef struct _dwg_object_APPID_CONTROL     dwg_obj_appid_control;

//-------------------------------------------------------------------------------

// Creates a new circle entity
dwg_ent_circle* dwg_ent_circle_new(int *error);

// Deletes a circle entity
void   dwg_ent_circle_delete(dwg_ent_circle *circle, int *error);

// Initializes a circle with its default values
dwg_ent_circle* dwg_ent_circle_init(dwg_ent_circle *circle);

// Get/Set the center point of a circle
void   dwg_ent_circle_get_center(dwg_ent_circle *circle, dwg_point_3d *point, int *error);
void   dwg_ent_circle_set_center(dwg_ent_circle *circle, dwg_point_3d *point, int *error);

// Get/Set the radius of a circle
double dwg_ent_circle_get_radius(dwg_ent_circle *circle, int *error);
void   dwg_ent_circle_set_radius(dwg_ent_circle *circle, double radius, int *error);

// Get/Set the thickness of a circle
double dwg_ent_circle_get_thickness(dwg_ent_circle *circle, int *error);
void   dwg_ent_circle_set_thickness(dwg_ent_circle *circle, double thickness, int *error);

// Get/Set the extrusion of a circle
void   dwg_ent_circle_set_extrusion(dwg_ent_circle *circle, dwg_point_3d *vector, int *error);
void   dwg_ent_circle_get_extrusion(dwg_ent_circle *circle, dwg_point_3d *vector, int *error);

//-------------------------------------------------------------------------------

// Creates a new line entity
dwg_ent_line* dwg_ent_line_new(int *error);

// Deletes a line entity
void   dwg_ent_line_delete(dwg_ent_line *line, int *error);

// Initializes a line with its default values
dwg_ent_line* dwg_ent_line_init(dwg_ent_line *line);

// Get/Set the start point of a line
void   dwg_ent_line_get_start_point(dwg_ent_line *line, dwg_point_3d *point, int *error);
void   dwg_ent_line_set_start_point(dwg_ent_line *line, dwg_point_3d *point, int *error);

// Get/Set the end point of a line
void   dwg_ent_line_get_end_point(dwg_ent_line *line, dwg_point_3d *point, int *error);
void   dwg_ent_line_set_end_point(dwg_ent_line *line, dwg_point_3d *point, int *error);

// Get/Set the thickness of a line
double dwg_ent_line_get_thickness(dwg_ent_line *line, int *error);
void   dwg_ent_line_set_thickness(dwg_ent_line *line, double thickness, int *error);

// Get/Set the extrusion of a line
void   dwg_ent_line_set_extrusion(dwg_ent_line *line, dwg_point_3d *vector, int *error);
void   dwg_ent_line_get_extrusion(dwg_ent_line *line, dwg_point_3d *vector, int *error);

//-------------------------------------------------------------------------------

// Creates a new arc entity
dwg_ent_arc* dwg_ent_arc_new(int *error);

// Deletes a arc entity
void dwg_ent_arc_delete(dwg_ent_arc *arc, int *error);

// Initializes a arc with its default values
dwg_ent_arc* dwg_ent_arc_init(dwg_ent_arc *arc);

// Get/Set the center point of a arc
void   dwg_ent_arc_get_center(dwg_ent_arc *arc, dwg_point_3d *point, int *error);
void   dwg_ent_arc_set_center(dwg_ent_arc *arc, dwg_point_3d *point, int *error);

// Get/Set the radius of a arc
double dwg_ent_arc_get_radius(dwg_ent_arc *arc, int *error);
void   dwg_ent_arc_set_radius(dwg_ent_arc *arc, double radius, int *error);

// Get/Set the thickness of arc
double dwg_ent_arc_get_thickness(dwg_ent_arc *arc, int *error);
void   dwg_ent_arc_set_thickness(dwg_ent_arc *arc, double thickness, int *error);

//Get/Set the extrusion of arc
void   dwg_ent_arc_get_extrusion(dwg_ent_arc *arc, dwg_point_3d *vector, int *error);
void   dwg_ent_arc_set_extrusion(dwg_ent_arc *arc, dwg_point_3d *vector, int *error);

// Get/set start angle arc
double dwg_ent_arc_get_start_angle(dwg_ent_arc *arc, int *error);
void   dwg_ent_arc_set_start_angle(dwg_ent_arc *arc, double start_angle, int *error);

// Get/set end angle of arc
double dwg_ent_arc_get_end_angle(dwg_ent_arc *arc, int *error);
void   dwg_ent_arc_set_end_angle(dwg_ent_arc *arc, double end_angle, int *error);

//-------------------------------------------------------------------------------

// Creates a new ellipse entity
dwg_ent_ellipse* dwg_ent_ellipse_new(int *error);

// Deletes a ellipse entity
void   dwg_ent_ellipse_delete(dwg_ent_ellipse *ellipse, int *error);

// Initializes a ellipse with its default values
dwg_ent_ellipse* dwg_ent_ellipse_init(dwg_ent_ellipse *ellipse);

// Get/Set center of ellipse
void   dwg_ent_ellipse_get_center(dwg_ent_ellipse *ellipse, dwg_point_3d *point, int *error);
void   dwg_ent_ellipse_set_center(dwg_ent_ellipse *ellipse, dwg_point_3d *point, int *error);

// Get/Set sm axis of ellipse
void   dwg_ent_ellipse_get_sm_axis(dwg_ent_ellipse *ellipse, dwg_point_3d *point, int *error);
void   dwg_ent_ellipse_set_sm_axis(dwg_ent_ellipse *ellipse, dwg_point_3d *point, int *error);

// Get/Set extrusion of ellipse
void   dwg_ent_ellipse_get_extrusion(dwg_ent_ellipse *ellipse, dwg_point_3d *vector, int *error);
void   dwg_ent_ellipse_set_extrusion(dwg_ent_ellipse *ellipse, dwg_point_3d *vector, int *error);

// Get/Set axis ratio of ellipse
double dwg_ent_ellipse_get_axis_ratio(dwg_ent_ellipse *ellipse, int *error);
void   dwg_ent_ellipse_set_axis_ratio(dwg_ent_ellipse *ellipse, double ratio, int *error);

// Get/Set start angle of ellipse
double dwg_ent_ellipse_get_start_angle(dwg_ent_ellipse *ellipse, int *error);
void   dwg_ent_ellipse_set_start_angle(dwg_ent_ellipse *ellipse, double start_angle, int *error);

// Get/Set end angle of ellipse
double dwg_ent_ellipse_get_end_angle(dwg_ent_ellipse *ellipse, int *error);
void   dwg_ent_ellipse_set_end_angle(dwg_ent_ellipse *ellipse, double end_angle, int *error);

//-------------------------------------------------------------------------------

// Get/Set text of text
void   dwg_ent_text_set_text(dwg_ent_text *text, char * text_value, int *error);
char * dwg_ent_text_get_text(dwg_ent_text *text, int *error);

// Get/Set insertion points of text
void   dwg_ent_text_get_insertion_point(dwg_ent_text *text, dwg_point_2d *point, int *error);
void   dwg_ent_text_set_insertion_point(dwg_ent_text *text, dwg_point_2d *point, int *error);

//Get/Set height of text
double dwg_ent_text_get_height(dwg_ent_text *text, int *error);
void   dwg_ent_text_set_height(dwg_ent_text *text, double height, int *error);

//Get/Set extrusion of text
void   dwg_ent_text_get_extrusion(dwg_ent_text *text, dwg_point_3d *vector, int *error);
void   dwg_ent_text_set_extrusion(dwg_ent_text *text, dwg_point_3d *vector, int *error);

//Get/Set thickness of text
double dwg_ent_text_get_thickness(dwg_ent_text *text, int *error);
void   dwg_ent_text_set_thickness(dwg_ent_text *text, double thickness, int *error);

//Get/Set rotation angle of text
double dwg_ent_text_get_rot_angle(dwg_ent_text *text, int *error);
void   dwg_ent_text_set_rot_angle(dwg_ent_text *text, double angle, int *error);

//Get/Set horizontal alignment angle of text
double dwg_ent_text_get_vert_align(dwg_ent_text *text, int *error);
void   dwg_ent_text_set_vert_align(dwg_ent_text *text, double alignment, int *error);

//Get/Set vertical alignment of text
double dwg_ent_text_get_horiz_align(dwg_ent_text *text, int *error);
void   dwg_ent_text_set_horiz_align(dwg_ent_text *text, double alignment, int *error);

//-------------------------------------------------------------------------------

// Get/Set text of attrib
void   dwg_ent_attrib_set_text(dwg_ent_attrib *attrib, char * text_value, int *error);
char * dwg_ent_attrib_get_text(dwg_ent_attrib *attrib, int *error);

// Get/Set insertion points of attrib
void   dwg_ent_attrib_get_insertion_point(dwg_ent_attrib *attrib, dwg_point_2d *point, int *error);
void   dwg_ent_attrib_set_insertion_point(dwg_ent_attrib *attrib, dwg_point_2d *point, int *error);

//Get/Set height of attrib
double dwg_ent_attrib_get_height(dwg_ent_attrib *attrib, int *error);
void   dwg_ent_attrib_set_height(dwg_ent_attrib *attrib, double height, int *error);

//Get/Set extrusion of attrib
void   dwg_ent_attrib_get_extrusion(dwg_ent_attrib *attrib, dwg_point_3d *vector, int *error);
void   dwg_ent_attrib_set_extrusion(dwg_ent_attrib *attrib, dwg_point_3d *vector, int *error);

//Get/Set thickness of attrib
double dwg_ent_attrib_get_thickness(dwg_ent_attrib *attrib, int *error);
void   dwg_ent_attrib_set_thickness(dwg_ent_attrib *attrib, double thickness, int *error);

//Get/Set rotation angle of attrib
double dwg_ent_attrib_get_rot_angle(dwg_ent_attrib *attrib, int *error);
void   dwg_ent_attrib_set_rot_angle(dwg_ent_attrib *attrib, double angle, int *error);

//Get/Set horizontal alignment angle of attrib
double dwg_ent_attrib_get_vert_align(dwg_ent_attrib *attrib, int *error);
void   dwg_ent_attrib_set_vert_align(dwg_ent_attrib *attrib, double alignment, int *error);

//Get/Set vertical alignment of attrib
double dwg_ent_attrib_get_horiz_align(dwg_ent_attrib *attrib, int *error);
void   dwg_ent_attrib_set_horiz_align(dwg_ent_attrib *attrib, double alignment, int *error);

//-------------------------------------------------------------------------------

// Get/Set text of attdef
void   dwg_ent_attdef_set_text(dwg_ent_attdef *attdef, char * default_value, int *error);
char * dwg_ent_attdef_get_text(dwg_ent_attdef *attdef, int *error);

// Get/Set insertion points of attdef
void   dwg_ent_attdef_get_insertion_point(dwg_ent_attdef *attdef, dwg_point_2d *point, int *error);
void   dwg_ent_attdef_set_insertion_point(dwg_ent_attdef *attdef, dwg_point_2d *point, int *error);

//Get/Set height of attdef
double dwg_ent_attdef_get_height(dwg_ent_attdef *attdef, int *error);
void   dwg_ent_attdef_set_height(dwg_ent_attdef *attdef, double height, int *error);

//Get/Set extrusion of attdef
void   dwg_ent_attdef_get_extrusion(dwg_ent_attdef *attdef, dwg_point_3d *vector, int *error);
void   dwg_ent_attdef_set_extrusion(dwg_ent_attdef *attdef, dwg_point_3d *vector, int *error);

//Get/Set thickness of attdef
double dwg_ent_attdef_get_thickness(dwg_ent_attdef *attdef, int *error);
void   dwg_ent_attdef_set_thickness(dwg_ent_attdef *attdef, double thickness, int *error);

//Get/Set rotation angle of attdef
double dwg_ent_attdef_get_rot_angle(dwg_ent_attdef *attdef, int *error);
void   dwg_ent_attdef_set_rot_angle(dwg_ent_attdef *attdef, double angle, int *error);

//Get/Set horizontal alignment angle of attdef
double dwg_ent_attdef_get_vert_align(dwg_ent_attdef *attdef, int *error);
void   dwg_ent_attdef_set_vert_align(dwg_ent_attdef *attdef, double alignment, int *error);

//Get/Set vertical alignment of attdef
double dwg_ent_attdef_get_horiz_align(dwg_ent_attdef *attdef, int *error);
void   dwg_ent_attdef_set_horiz_align(dwg_ent_attdef *attdef, double alignment, int *error);

//--------------------------------------------------------------------------------

void   dwg_ent_point_set_point(dwg_ent_point *point, dwg_point_3d *retpoint, int *error);
void   dwg_ent_point_get_point(dwg_ent_point *point, dwg_point_3d *retpoint, int *error);

double dwg_ent_point_get_thickness(dwg_ent_point *point, int *error);
void   dwg_ent_point_set_thickness(dwg_ent_point *point, double thickness, int *error);

void   dwg_ent_point_set_extrusion(dwg_ent_point *point, dwg_point_3d *retpoint, int *error);
void   dwg_ent_point_get_extrusion(dwg_ent_point *point, dwg_point_3d *retpoint, int *error);

//---------------------------------------------------------------------------------

double dwg_ent_solid_get_thickness(dwg_ent_solid *solid, int *error);
void   dwg_ent_solid_set_thickness(dwg_ent_solid *solid, double thickness, int *error);

double dwg_ent_solid_get_elevation(dwg_ent_solid *solid, int *error);
void   dwg_ent_solid_set_elevation(dwg_ent_solid *solid, double elevation, int *error);

void   dwg_ent_solid_get_corner1(dwg_ent_solid *solid, dwg_point_2d *point, int *error);
void   dwg_ent_solid_set_corner1(dwg_ent_solid *solid, dwg_point_2d *point, int *error);

void   dwg_ent_solid_get_corner2(dwg_ent_solid *solid, dwg_point_2d *point, int *error);
void   dwg_ent_solid_set_corner2(dwg_ent_solid *solid, dwg_point_2d *point, int *error);

void   dwg_ent_solid_get_corner3(dwg_ent_solid *solid, dwg_point_2d *point, int *error);
void   dwg_ent_solid_set_corner3(dwg_ent_solid *solid, dwg_point_2d *point, int *error);

void   dwg_ent_solid_get_corner4(dwg_ent_solid *solid, dwg_point_2d *point, int *error);
void   dwg_ent_solid_set_corner4(dwg_ent_solid *solid, dwg_point_2d *point, int *error);

void   dwg_ent_solid_get_extrusion(dwg_ent_solid *solid, dwg_point_3d *vector, int *error);
void   dwg_ent_solid_set_extrusion(dwg_ent_solid *solid, dwg_point_3d *vector, int *error);

//--------------------------------------------------------------------------------

// Get/Set text of block
void   dwg_ent_block_set_name(dwg_ent_block *block, char * name, int *error);
char * dwg_ent_block_get_name(dwg_ent_block *block, int *error);

//--------------------------------------------------------------------------------

void   dwg_ent_ray_get_point(dwg_ent_ray *ray, dwg_point_3d *point, int *error);
void   dwg_ent_ray_set_point(dwg_ent_ray *ray, dwg_point_3d *point, int *error);

void   dwg_ent_ray_get_vector(dwg_ent_ray *ray, dwg_point_3d *vector, int *error);
void   dwg_ent_ray_set_vector(dwg_ent_ray *ray, dwg_point_3d *vector, int *error);

//--------------------------------------------------------------------------------

void   dwg_ent_xline_get_point(dwg_ent_xline *xline, dwg_point_3d *point, int *error);
void   dwg_ent_xline_set_point(dwg_ent_xline *xline, dwg_point_3d *point, int *error);

void   dwg_ent_xline_get_vector(dwg_ent_xline *xline, dwg_point_3d *vector, int *error);
void   dwg_ent_xline_set_vector(dwg_ent_xline *xline, dwg_point_3d *vector, int *error);

//--------------------------------------------------------------------------------

double dwg_ent_trace_get_thickness(dwg_ent_trace *trace, int *error);
void   dwg_ent_trace_set_thickness(dwg_ent_trace *trace, double thickness, int *error);

double dwg_ent_trace_get_elevation(dwg_ent_trace *trace, int *error);
void   dwg_ent_trace_set_elevation(dwg_ent_trace *trace, double elevation, int *error);

void   dwg_ent_trace_get_corner1(dwg_ent_trace *trace, dwg_point_2d *point, int *error);
void   dwg_ent_trace_set_corner1(dwg_ent_trace *trace, dwg_point_2d *point, int *error);

void   dwg_ent_trace_get_corner2(dwg_ent_trace *trace, dwg_point_2d *point, int *error);
void   dwg_ent_trace_set_corner2(dwg_ent_trace *trace, dwg_point_2d *point, int *error);

void   dwg_ent_trace_get_corner3(dwg_ent_trace *trace, dwg_point_2d *point, int *error);
void   dwg_ent_trace_set_corner3(dwg_ent_trace *trace, dwg_point_2d *point, int *error);

void   dwg_ent_trace_get_corner4(dwg_ent_trace *trace, dwg_point_2d *point, int *error);
void   dwg_ent_trace_set_corner4(dwg_ent_trace *trace, dwg_point_2d *point, int *error);

void   dwg_ent_trace_get_extrusion(dwg_ent_trace *trace, dwg_point_3d *vector, int *error);
void   dwg_ent_trace_set_extrusion(dwg_ent_trace *trace, dwg_point_3d *vector, int *error);

//--------------------------------------------------------------------------------

char   dwg_ent_vertex_3d_get_flags(dwg_ent_vertex_3d *vert, int *error);
void   dwg_ent_vertex_3d_set_flags(dwg_ent_vertex_3d *vert, char flags, int *error);

void   dwg_ent_vertex_3d_get_point(dwg_ent_vertex_3d *vert, dwg_point_3d *point, int *error);
void   dwg_ent_vertex_3d_set_point(dwg_ent_vertex_3d *vert, dwg_point_3d *point, int *error);

//--------------------------------------------------------------------------------

char   dwg_ent_vertex_mesh_get_flags(dwg_ent_vertex_mesh *vert, int *error);
void   dwg_ent_vertex_mesh_set_flags(dwg_ent_vertex_mesh *vert, char flags, int *error);

void   dwg_ent_vertex_mesh_get_point(dwg_ent_vertex_mesh *vert, dwg_point_3d *point, int *error);
void   dwg_ent_vertex_mesh_set_point(dwg_ent_vertex_mesh *vert, dwg_point_3d *point, int *error);

//--------------------------------------------------------------------------------

char   dwg_ent_vertex_pface_get_flags(dwg_ent_vertex_pface *vert, int *error);
void   dwg_ent_vertex_pface_set_flags(dwg_ent_vertex_pface *vert, char flags, int *error);

void   dwg_ent_vertex_pface_get_point(dwg_ent_vertex_pface *vert, dwg_point_3d *point, int *error);
void   dwg_ent_vertex_pface_set_point(dwg_ent_vertex_pface *vert, dwg_point_3d *point, int *error);

//--------------------------------------------------------------------------------

char   dwg_ent_vertex_2d_get_flags(dwg_ent_vertex_2d *vert, int *error);
void   dwg_ent_vertex_2d_set_flags(dwg_ent_vertex_2d *vert, char flags, int *error);

void   dwg_ent_vertex_2d_get_point(dwg_ent_vertex_2d *vert, dwg_point_3d *point, int *error);
void   dwg_ent_vertex_2d_set_point(dwg_ent_vertex_2d *vert, dwg_point_3d *point, int *error);

double dwg_ent_vertex_2d_get_start_width(dwg_ent_vertex_2d *vert, int *error);
void   dwg_ent_vertex_2d_set_start_width(dwg_ent_vertex_2d *vert, double start_width, int *error);

double dwg_ent_vertex_2d_get_end_width(dwg_ent_vertex_2d *vert, int *error);
void   dwg_ent_vertex_2d_set_end_width(dwg_ent_vertex_2d *vert, double end_width, int *error);

double dwg_ent_vertex_2d_get_bulge(dwg_ent_vertex_2d *vert, int *error);
void   dwg_ent_vertex_2d_set_bulge(dwg_ent_vertex_2d *vert, double bulge, int *error);

double dwg_ent_vertex_2d_get_tangent_dir(dwg_ent_vertex_2d *vert, int *error);
void   dwg_ent_vertex_2d_set_tangent_dir(dwg_ent_vertex_2d *vert, double tangent_dir, int *error);

//--------------------------------------------------------------------------------

void   dwg_ent_insert_get_ins_pt(dwg_ent_insert *insert, dwg_point_3d *point, int *error);
void   dwg_ent_insert_set_ins_pt(dwg_ent_insert *insert, dwg_point_3d *point, int *error);

char   dwg_ent_insert_get_scale_flag(dwg_ent_insert *insert, int *error);
void   dwg_ent_insert_set_scale_flag(dwg_ent_insert *insert, char flags, int *error);

void   dwg_ent_insert_get_scale(dwg_ent_insert *insert, dwg_point_3d *point, int *error);
void   dwg_ent_insert_set_scale(dwg_ent_insert *insert, dwg_point_3d *point, int *error);

double dwg_ent_insert_get_rotation_angle(dwg_ent_insert *insert, int *error);
void   dwg_ent_insert_set_rotation_angle(dwg_ent_insert *insert, double rot_ang, int *error);

void   dwg_ent_insert_get_extrusion(dwg_ent_insert *insert, dwg_point_3d *point, int *error);
void   dwg_ent_insert_set_extrusion(dwg_ent_insert *insert, dwg_point_3d *point, int *error);

char   dwg_ent_insert_get_has_attribs(dwg_ent_insert *insert, int *error);
void   dwg_ent_insert_set_has_attribs(dwg_ent_insert *insert, char attribs, int *error);

long   dwg_ent_insert_get_owned_obj_count(dwg_ent_insert *insert, int *error);
void   dwg_ent_insert_set_owned_obj_count(dwg_ent_insert *insert, long count, int *error);

//--------------------------------------------------------------------------------

void   dwg_ent_minsert_get_ins_pt(dwg_ent_minsert *minsert, dwg_point_3d *point, int *error);
void   dwg_ent_minsert_set_ins_pt(dwg_ent_minsert *minsert, dwg_point_3d *point, int *error);

char   dwg_ent_minsert_get_scale_flag(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_scale_flag(dwg_ent_minsert *minsert, char flags, int *error);

void   dwg_ent_minsert_get_scale(dwg_ent_minsert *minsert, dwg_point_3d *point, int *error);
void   dwg_ent_minsert_set_scale(dwg_ent_minsert *minsert, dwg_point_3d *point, int *error);

double dwg_ent_minsert_get_rotation_angle(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_rotation_angle(dwg_ent_minsert *minsert, double rot_ang, int *error);

void   dwg_ent_minsert_get_extrusion(dwg_ent_minsert *minsert, dwg_point_3d *point, int *error);
void   dwg_ent_minsert_set_extrusion(dwg_ent_minsert *minsert, dwg_point_3d *point, int *error);

char   dwg_ent_minsert_get_has_attribs(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_has_attribs(dwg_ent_minsert *minsert, char attribs, int *error);

long   dwg_ent_minsert_get_owned_obj_count(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_owned_obj_count(dwg_ent_minsert *minsert, long count, int *error);

long   dwg_ent_minsert_get_numcols(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_numcols(dwg_ent_minsert *minsert, long cols, int *error);

long   dwg_ent_minsert_get_numrows(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_numrows(dwg_ent_minsert *minsert, long cols, int *error);

double dwg_ent_minsert_get_col_spacing(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_col_spacing(dwg_ent_minsert *minsert, double spacing, int *error);

double dwg_ent_minsert_get_row_spacing(dwg_ent_minsert *minsert, int *error);
void   dwg_ent_minsert_set_row_spacing(dwg_ent_minsert *minsert, double spacing, int *error);

//--------------------------------------------------------------------------------

char * dwg_obj_mlinstyle_get_name(dwg_obj_mlinestyle *mlinestyle, int *error);
void   dwg_obj_mlinestyle_set_name(dwg_obj_mlinestyle *mlinestyle, char * name, int *error);

char * dwg_obj_mlinestyle_get_desc(dwg_obj_mlinestyle *mlinestyle, int *error);
void   dwg_obj_mlinestyle_set_desc(dwg_obj_mlinestyle *mlinestyle, char * desc, int *error);

int    dwg_obj_mlinestyle_get_flags(dwg_obj_mlinestyle *mlinestyle, int *error);
void   dwg_obj_mlinestyle_set_flags(dwg_obj_mlinestyle *mlinestyle, int flags, int *error);

double dwg_obj_mlinestyle_get_start_angle(dwg_obj_mlinestyle *mlinestyle, int *error);
void   dwg_obj_mlinestyle_set_start_angle(dwg_obj_mlinestyle *mlinestyle, double startang, int *error);

double dwg_obj_mlinestyle_get_end_angle(dwg_obj_mlinestyle *mlinestyle, int *error);
void   dwg_obj_mlinestyle_set_end_angle(dwg_obj_mlinestyle *mlinestyle, double endang, int *error);

char   dwg_obj_mlinestyle_get_linesinstyle(dwg_obj_mlinestyle *mlinestyle, int *error);
void   dwg_obj_mlinestyle_set_linesinstyle(dwg_obj_mlinestyle *mlinestyle, char linesinstyle, int *error);

//--------------------------------------------------------------------------------

int    dwg_obj_appid_control_get_num_entries(dwg_obj_appid_control *appid, int *error);
void   dwg_obj_appid_control_set_num_entries(dwg_obj_appid_control *appid, int entries, int *error);

//--------------------------------------------------------------------------------

char * dwg_obj_appid_get_entry_name(dwg_obj_appid *appid, int *error);
void   dwg_obj_appid_set_entry_name(dwg_obj_appid *appid, char * entry_name, int *error);

char   dwg_obj_appid_get_flag(dwg_obj_appid *appid, int *error);
void   dwg_obj_appid_set_flag(dwg_obj_appid *appid, char flag, int *error);

dwg_obj_appid_control dwg_obj_appid_get_appid_control(dwg_obj_appid *appid, int *error);

//--------------------------------------------------------------------------------

double dwg_ent_dim_ordinate_get_elevation_ecs11(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_elevation_ecs11(dwg_ent_dim_ordinate *dim, double elevation_ecs11, int *error);

double dwg_ent_dim_ordinate_get_elevation_ecs12(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_elevation_ecs12(dwg_ent_dim_ordinate *dim, double elevation_ecs12, int *error);

char   dwg_ent_dim_ordinate_get_flags1(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_flags1(dwg_ent_dim_ordinate *dim, char flag, int *error);

double dwg_ent_dim_ordinate_get_act_measurement(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_act_measurement(dwg_ent_dim_ordinate *dim, double act_measurement, int *error);

double dwg_ent_dim_ordinate_get_horiz_dir(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_horiz_dir(dwg_ent_dim_ordinate *dim, double horiz_dir, int *error);

double dwg_ent_dim_ordinate_get_lspace_factor(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_lspace_factor(dwg_ent_dim_ordinate *dim, double factor, int *error);

unsigned int dwg_ent_dim_ordinate_get_lspace_style(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_lspace_style(dwg_ent_dim_ordinate *dim, unsigned int style, int *error);

unsigned int dwg_ent_dim_ordinate_get_attachment_point(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_attachment_point(dwg_ent_dim_ordinate *dim, unsigned int point, int *error);

void   dwg_ent_dim_ordinate_set_extrusion(dwg_ent_dim_ordinate *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ordinate_get_extrusion(dwg_ent_dim_ordinate *dim, dwg_point_3d *point, int *error);

char * dwg_ent_dim_ordinate_get_user_text(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_user_text(dwg_ent_dim_ordinate *dim, char * text, int *error);

double dwg_ent_dim_ordinate_get_text_rot(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_text_rot(dwg_ent_dim_ordinate *dim, double rot, int *error);

double dwg_ent_dim_ordinate_get_ins_rotation(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_ins_rotation(dwg_ent_dim_ordinate *dim, double rot, int *error);

char   dwg_ent_dim_ordinate_get_flip_arrow1(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_flip_arrow1(dwg_ent_dim_ordinate *dim, char flip_arrow, int *error);

char   dwg_ent_dim_ordinate_get_flip_arrow2(dwg_ent_dim_ordinate *dim, int *error);
void   dwg_ent_dim_ordinate_set_flip_arrow2(dwg_ent_dim_ordinate *dim, char flip_arrow, int *error);

void   dwg_ent_dim_ordinate_set_text_mid_pt(dwg_ent_dim_ordinate *dim, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ordinate_get_text_mid_pt(dwg_ent_dim_ordinate *dim, dwg_point_2d *point, int *error);

void   dwg_ent_dim_ordinate_set_ins_scale(dwg_ent_dim_ordinate *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ordinate_get_ins_scale(dwg_ent_dim_ordinate *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ordinate_set_12_pt(dwg_ent_dim_ordinate *dim, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ordinate_get_12_pt(dwg_ent_dim_ordinate *dim, dwg_point_2d *point, int *error);

void   dwg_ent_dim_ordinate_set_10_pt(dwg_ent_dim_ordinate *ord, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ordinate_get_10_pt(dwg_ent_dim_ordinate *ord, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ordinate_set_13_pt(dwg_ent_dim_ordinate *ord, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ordinate_get_13_pt(dwg_ent_dim_ordinate *ord, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ordinate_set_14_pt(dwg_ent_dim_ordinate *ord, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ordinate_get_14_pt(dwg_ent_dim_ordinate *ord, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ordinate_set_flags2(dwg_ent_dim_ordinate *ord, char flag, int *error);
char   dwg_ent_dim_ordinate_get_flags2(dwg_ent_dim_ordinate *ord, int *error);

//------------------------------------------------------------------------------------

double dwg_ent_dim_linear_get_elevation_ecs11(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_elevation_ecs11(dwg_ent_dim_linear *dim, double elevation_ecs11, int *error);

double dwg_ent_dim_linear_get_elevation_ecs12(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_elevation_ecs12(dwg_ent_dim_linear *dim, double elevation_ecs12, int *error);

char   dwg_ent_dim_linear_get_flags1(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_flags1(dwg_ent_dim_linear *dim, char flag, int *error);

double dwg_ent_dim_linear_get_act_measurement(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_act_measurement(dwg_ent_dim_linear *dim, double act_measurement, int *error);

double dwg_ent_dim_linear_get_horiz_dir(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_horiz_dir(dwg_ent_dim_linear *dim, double horiz_dir, int *error);

double dwg_ent_dim_linear_get_lspace_factor(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_lspace_factor(dwg_ent_dim_linear *dim, double factor, int *error);

unsigned int dwg_ent_dim_linear_get_lspace_style(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_lspace_style(dwg_ent_dim_linear *dim, unsigned int style, int *error);

unsigned int dwg_ent_dim_linear_get_attachment_point(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_attachment_point(dwg_ent_dim_linear *dim, unsigned int point, int *error);

void   dwg_ent_dim_linear_set_extrusion(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_linear_get_extrusion(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);

char * dwg_ent_dim_linear_get_user_text(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_user_text(dwg_ent_dim_linear *dim, char * text, int *error);

double dwg_ent_dim_linear_get_text_rot(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_text_rot(dwg_ent_dim_linear *dim, double rot, int *error);

double dwg_ent_dim_linear_get_ins_rotation(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_ins_rotation(dwg_ent_dim_linear *dim, double rot, int *error);

char   dwg_ent_dim_linear_get_flip_arrow1(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_flip_arrow1(dwg_ent_dim_linear *dim, char flip_arrow, int *error);

char   dwg_ent_dim_linear_get_flip_arrow2(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_flip_arrow2(dwg_ent_dim_linear *dim, char flip_arrow, int *error);

void   dwg_ent_dim_linear_set_text_mid_pt(dwg_ent_dim_linear *dim, dwg_point_2d *point, int *error);
void   dwg_ent_dim_linear_get_text_mid_pt(dwg_ent_dim_linear *dim, dwg_point_2d *point, int *error);

void   dwg_ent_dim_linear_set_ins_scale(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_linear_get_ins_scale(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_linear_set_12_pt(dwg_ent_dim_linear *dim, dwg_point_2d *point, int *error);
void   dwg_ent_dim_linear_get_12_pt(dwg_ent_dim_linear *dim, dwg_point_2d *point, int *error);

void   dwg_ent_dim_linear_set_10_pt(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_linear_get_10_pt(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_linear_set_13_pt(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_linear_get_13_pt(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_linear_set_14_pt(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_linear_get_14_pt(dwg_ent_dim_linear *dim, dwg_point_3d *point, int *error);

double dwg_ent_dim_linear_get_dim_rot(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_dim_rot(dwg_ent_dim_linear *dim, double rot, int *error);

double dwg_ent_dim_linear_get_ext_line_rotation(dwg_ent_dim_linear *dim, int *error);
void   dwg_ent_dim_linear_set_ext_line_rotation(dwg_ent_dim_linear *dim, double rot, int *error);

//------------------------------------------------------------------------------------

double dwg_ent_dim_aligned_get_elevation_ecs11(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_elevation_ecs11(dwg_ent_dim_aligned *dim, double elevation_ecs11, int *error);

double dwg_ent_dim_aligned_get_elevation_ecs12(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_elevation_ecs12(dwg_ent_dim_aligned *dim, double elevation_ecs12, int *error);

char   dwg_ent_dim_aligned_get_flags1(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_flags1(dwg_ent_dim_aligned *dim, char flag, int *error);

double dwg_ent_dim_aligned_get_act_measurement(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_act_measurement(dwg_ent_dim_aligned *dim, double act_measurement, int *error);

double dwg_ent_dim_aligned_get_horiz_dir(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_horiz_dir(dwg_ent_dim_aligned *dim, double horiz_dir, int *error);

double dwg_ent_dim_aligned_get_lspace_factor(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_lspace_factor(dwg_ent_dim_aligned *dim, double factor, int *error);

unsigned int dwg_ent_dim_aligned_get_lspace_style(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_lspace_style(dwg_ent_dim_aligned *dim, unsigned int style, int *error);

unsigned int dwg_ent_dim_aligned_get_attachment_point(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_attachment_point(dwg_ent_dim_aligned *dim, unsigned int point, int *error);

void   dwg_ent_dim_aligned_set_extrusion(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_aligned_get_extrusion(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);

char * dwg_ent_dim_aligned_get_user_text(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_user_text(dwg_ent_dim_aligned *dim, char * text, int *error);

double dwg_ent_dim_aligned_get_text_rot(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_text_rot(dwg_ent_dim_aligned *dim, double rot, int *error);

double dwg_ent_dim_aligned_get_ins_rotation(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_ins_rotation(dwg_ent_dim_aligned *dim, double rot, int *error);

char   dwg_ent_dim_aligned_get_flip_arrow1(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_flip_arrow1(dwg_ent_dim_aligned *dim, char flip_arrow, int *error);

char   dwg_ent_dim_aligned_get_flip_arrow2(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_flip_arrow2(dwg_ent_dim_aligned *dim, char flip_arrow, int *error);

void   dwg_ent_dim_aligned_set_text_mid_pt(dwg_ent_dim_aligned *dim, dwg_point_2d *point, int *error);
void   dwg_ent_dim_aligned_get_text_mid_pt(dwg_ent_dim_aligned *dim, dwg_point_2d *point, int *error);

void   dwg_ent_dim_aligned_set_ins_scale(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_aligned_get_ins_scale(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_aligned_set_12_pt(dwg_ent_dim_aligned *dim, dwg_point_2d *point, int *error);
void   dwg_ent_dim_aligned_get_12_pt(dwg_ent_dim_aligned *dim, dwg_point_2d *point, int *error);

void   dwg_ent_dim_aligned_set_10_pt(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_aligned_get_10_pt(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_aligned_set_13_pt(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_aligned_get_13_pt(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);

void   dwg_ent_dim_aligned_set_14_pt(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);
void   dwg_ent_dim_aligned_get_14_pt(dwg_ent_dim_aligned *dim, dwg_point_3d *point, int *error);

double dwg_ent_dim_aligned_get_ext_line_rotation(dwg_ent_dim_aligned *dim, int *error);
void   dwg_ent_dim_aligned_set_ext_line_rotation(dwg_ent_dim_aligned *dim, double rot, int *error);

//------------------------------------------------------------------------------------

double dwg_ent_dim_ang3pt_get_elevation_ecs11(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_elevation_ecs11(dwg_ent_dim_ang3pt *ang, double elevation_ecs11, int *error);

double dwg_ent_dim_ang3pt_get_elevation_ecs12(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_elevation_ecs12(dwg_ent_dim_ang3pt *ang, double elevation_ecs12, int *error);

char   dwg_ent_dim_ang3pt_get_flags1(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_flags1(dwg_ent_dim_ang3pt *ang, char flag, int *error);

double dwg_ent_dim_ang3pt_get_act_measurement(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_act_measurement(dwg_ent_dim_ang3pt *ang, double act_measurement, int *error);

double dwg_ent_dim_ang3pt_get_horiz_dir(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_horiz_dir(dwg_ent_dim_ang3pt *ang, double horiz_dir, int *error);

double dwg_ent_dim_ang3pt_get_lspace_factor(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_lspace_factor(dwg_ent_dim_ang3pt *ang, double factor, int *error);

unsigned int dwg_ent_dim_ang3pt_get_lspace_style(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_lspace_style(dwg_ent_dim_ang3pt *ang, unsigned int style, int *error);

unsigned int dwg_ent_dim_ang3pt_get_attachment_point(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_attachment_point(dwg_ent_dim_ang3pt *ang, unsigned int point, int *error);

void   dwg_ent_dim_ang3pt_set_extrusion(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang3pt_get_extrusion(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);

char * dwg_ent_dim_ang3pt_get_user_text(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_user_text(dwg_ent_dim_ang3pt *ang, char * text, int *error);

double dwg_ent_dim_ang3pt_get_text_rot(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_text_rot(dwg_ent_dim_ang3pt *ang, double rot, int *error);

double dwg_ent_dim_ang3pt_get_ins_rotation(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_ins_rotation(dwg_ent_dim_ang3pt *ang, double rot, int *error);

char   dwg_ent_dim_ang3pt_get_flip_arrow1(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_flip_arrow1(dwg_ent_dim_ang3pt *ang, char flip_arrow, int *error);

char   dwg_ent_dim_ang3pt_get_flip_arrow2(dwg_ent_dim_ang3pt *ang, int *error);
void   dwg_ent_dim_ang3pt_set_flip_arrow2(dwg_ent_dim_ang3pt *ang, char flip_arrow, int *error);

void   dwg_ent_dim_ang3pt_set_text_mid_pt(dwg_ent_dim_ang3pt *ang, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ang3pt_get_text_mid_pt(dwg_ent_dim_ang3pt *ang, dwg_point_2d *point, int *error);

void   dwg_ent_dim_ang3pt_set_ins_scale(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang3pt_get_ins_scale(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang3pt_set_12_pt(dwg_ent_dim_ang3pt *ang, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ang3pt_get_12_pt(dwg_ent_dim_ang3pt *ang, dwg_point_2d *point, int *error);

void   dwg_ent_dim_ang3pt_set_10_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang3pt_get_10_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang3pt_set_13_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang3pt_get_13_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang3pt_set_14_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang3pt_get_14_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang3pt_set_15_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang3pt_get_15_pt(dwg_ent_dim_ang3pt *ang, dwg_point_3d *point, int *error);

//------------------------------------------------------------------------------------

double dwg_ent_dim_ang2ln_get_elevation_ecs11(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_elevation_ecs11(dwg_ent_dim_ang2ln *ang, double elevation_ecs11, int *error);

double dwg_ent_dim_ang2ln_get_elevation_ecs12(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_elevation_ecs12(dwg_ent_dim_ang2ln *ang, double elevation_ecs12, int *error);

char   dwg_ent_dim_ang2ln_get_flags1(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_flags1(dwg_ent_dim_ang2ln *ang, char flag, int *error);

double dwg_ent_dim_ang2ln_get_act_measurement(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_act_measurement(dwg_ent_dim_ang2ln *ang, double act_measurement, int *error);

double dwg_ent_dim_ang2ln_get_horiz_dir(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_horiz_dir(dwg_ent_dim_ang2ln *ang, double horiz_dir, int *error);

double dwg_ent_dim_ang2ln_get_lspace_factor(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_lspace_factor(dwg_ent_dim_ang2ln *ang, double factor, int *error);

unsigned int dwg_ent_dim_ang2ln_get_lspace_style(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_lspace_style(dwg_ent_dim_ang2ln *ang, unsigned int style, int *error);

unsigned int dwg_ent_dim_ang2ln_get_attachment_point(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_attachment_point(dwg_ent_dim_ang2ln *ang, unsigned int point, int *error);

void   dwg_ent_dim_ang2ln_set_extrusion(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang2ln_get_extrusion(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);

char * dwg_ent_dim_ang2ln_get_user_text(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_user_text(dwg_ent_dim_ang2ln *ang, char * text, int *error);

double dwg_ent_dim_ang2ln_get_text_rot(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_text_rot(dwg_ent_dim_ang2ln *ang, double rot, int *error);

double dwg_ent_dim_ang2ln_get_ins_rotation(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_ins_rotation(dwg_ent_dim_ang2ln *ang, double rot, int *error);

char   dwg_ent_dim_ang2ln_get_flip_arrow1(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_flip_arrow1(dwg_ent_dim_ang2ln *ang, char flip_arrow, int *error);

char   dwg_ent_dim_ang2ln_get_flip_arrow2(dwg_ent_dim_ang2ln *ang, int *error);
void   dwg_ent_dim_ang2ln_set_flip_arrow2(dwg_ent_dim_ang2ln *ang, char flip_arrow, int *error);

void   dwg_ent_dim_ang2ln_set_text_mid_pt(dwg_ent_dim_ang2ln *ang, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ang2ln_get_text_mid_pt(dwg_ent_dim_ang2ln *ang, dwg_point_2d *point, int *error);

void   dwg_ent_dim_ang2ln_set_ins_scale(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang2ln_get_ins_scale(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang2ln_set_12_pt(dwg_ent_dim_ang2ln *ang, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ang2ln_get_12_pt(dwg_ent_dim_ang2ln *ang, dwg_point_2d *point, int *error);

void   dwg_ent_dim_ang2ln_set_10_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang2ln_get_10_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang2ln_set_13_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang2ln_get_13_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang2ln_set_14_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang2ln_get_14_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang2ln_set_15_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);
void   dwg_ent_dim_ang2ln_get_15_pt(dwg_ent_dim_ang2ln *ang, dwg_point_3d *point, int *error);

void   dwg_ent_dim_ang2ln_set_16_pt(dwg_ent_dim_ang2ln *ang, dwg_point_2d *point, int *error);
void   dwg_ent_dim_ang2ln_get_16_pt(dwg_ent_dim_ang2ln *ang, dwg_point_2d *point, int *error);

//------------------------------------------------------------------------------------

double dwg_ent_dim_radius_get_elevation_ecs11(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_elevation_ecs11(dwg_ent_dim_radius *radius, double elevation_ecs11, int *error);

double dwg_ent_dim_radius_get_elevation_ecs12(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_elevation_ecs12(dwg_ent_dim_radius *radius, double elevation_ecs12, int *error);

char   dwg_ent_dim_radius_get_flags1(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_flags1(dwg_ent_dim_radius *radius, char flag, int *error);

double dwg_ent_dim_radius_get_act_measurement(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_act_measurement(dwg_ent_dim_radius *radius, double act_measurement, int *error);

double dwg_ent_dim_radius_get_horiz_dir(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_horiz_dir(dwg_ent_dim_radius *radius, double horiz_dir, int *error);

double dwg_ent_dim_radius_get_lspace_factor(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_lspace_factor(dwg_ent_dim_radius *radius, double factor, int *error);

unsigned int dwg_ent_dim_radius_get_lspace_style(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_lspace_style(dwg_ent_dim_radius *radius, unsigned int style, int *error);

unsigned int dwg_ent_dim_radius_get_attachment_point(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_attachment_point(dwg_ent_dim_radius *radius, unsigned int point, int *error);

void   dwg_ent_dim_radius_set_extrusion(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);
void   dwg_ent_dim_radius_get_extrusion(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);

char * dwg_ent_dim_radius_get_user_text(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_user_text(dwg_ent_dim_radius *radius, char * text, int *error);

double dwg_ent_dim_radius_get_text_rot(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_text_rot(dwg_ent_dim_radius *radius, double rot, int *error);

double dwg_ent_dim_radius_get_ins_rotation(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_ins_rotation(dwg_ent_dim_radius *radius, double rot, int *error);

char   dwg_ent_dim_radius_get_flip_arrow1(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_flip_arrow1(dwg_ent_dim_radius *radius, char flip_arrow, int *error);

char   dwg_ent_dim_radius_get_flip_arrow2(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_flip_arrow2(dwg_ent_dim_radius *radius, char flip_arrow, int *error);

void   dwg_ent_dim_radius_set_text_mid_pt(dwg_ent_dim_radius *radius, dwg_point_2d *point, int *error);
void   dwg_ent_dim_radius_get_text_mid_pt(dwg_ent_dim_radius *radius, dwg_point_2d *point, int *error);

void   dwg_ent_dim_radius_set_ins_scale(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);
void   dwg_ent_dim_radius_get_ins_scale(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);

void   dwg_ent_dim_radius_set_12_pt(dwg_ent_dim_radius *radius, dwg_point_2d *point, int *error);
void   dwg_ent_dim_radius_get_12_pt(dwg_ent_dim_radius *radius, dwg_point_2d *point, int *error);

void   dwg_ent_dim_radius_set_10_pt(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);
void   dwg_ent_dim_radius_get_10_pt(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);

void   dwg_ent_dim_radius_set_15_pt(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);
void   dwg_ent_dim_radius_get_15_pt(dwg_ent_dim_radius *radius, dwg_point_3d *point, int *error);

double dwg_ent_dim_radius_get_leader_len(dwg_ent_dim_radius *radius, int *error);
void   dwg_ent_dim_radius_set_leader_len(dwg_ent_dim_radius *radius, double length, int *error);

//------------------------------------------------------------------------------------

double dwg_ent_dim_diameter_get_elevation_ecs11(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_elevation_ecs11(dwg_ent_dim_diameter *dia, double elevation_ecs11, int *error);

double dwg_ent_dim_diameter_get_elevation_ecs12(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_elevation_ecs12(dwg_ent_dim_diameter *dia, double elevation_ecs12, int *error);

char   dwg_ent_dim_diameter_get_flags1(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_flags1(dwg_ent_dim_diameter *dia, char flag, int *error);

double dwg_ent_dim_diameter_get_act_measurement(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_act_measurement(dwg_ent_dim_diameter *dia, double act_measurement, int *error);

double dwg_ent_dim_diameter_get_horiz_dir(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_horiz_dir(dwg_ent_dim_diameter *dia, double horiz_dir, int *error);

double dwg_ent_dim_diameter_get_lspace_factor(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_lspace_factor(dwg_ent_dim_diameter *dia, double factor, int *error);

unsigned int dwg_ent_dim_diameter_get_lspace_style(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_lspace_style(dwg_ent_dim_diameter *dia, unsigned int style, int *error);

unsigned int dwg_ent_dim_diameter_get_attachment_point(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_attachment_point(dwg_ent_dim_diameter *dia, unsigned int point, int *error);

void   dwg_ent_dim_diameter_set_extrusion(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);
void   dwg_ent_dim_diameter_get_extrusion(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);

char * dwg_ent_dim_diameter_get_user_text(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_user_text(dwg_ent_dim_diameter *dia, char * text, int *error);

double dwg_ent_dim_diameter_get_text_rot(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_text_rot(dwg_ent_dim_diameter *dia, double rot, int *error);

double dwg_ent_dim_diameter_get_ins_rotation(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_ins_rotation(dwg_ent_dim_diameter *dia, double rot, int *error);

char   dwg_ent_dim_diameter_get_flip_arrow1(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_flip_arrow1(dwg_ent_dim_diameter *dia, char flip_arrow, int *error);

char   dwg_ent_dim_diameter_get_flip_arrow2(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_flip_arrow2(dwg_ent_dim_diameter *dia, char flip_arrow, int *error);

void   dwg_ent_dim_diameter_set_text_mid_pt(dwg_ent_dim_diameter *dia, dwg_point_2d *point, int *error);
void   dwg_ent_dim_diameter_get_text_mid_pt(dwg_ent_dim_diameter *dia, dwg_point_2d *point, int *error);

void   dwg_ent_dim_diameter_set_ins_scale(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);
void   dwg_ent_dim_diameter_get_ins_scale(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);

void   dwg_ent_dim_diameter_set_12_pt(dwg_ent_dim_diameter *dia, dwg_point_2d *point, int *error);
void   dwg_ent_dim_diameter_get_12_pt(dwg_ent_dim_diameter *dia, dwg_point_2d *point, int *error);

void   dwg_ent_dim_diameter_set_10_pt(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);
void   dwg_ent_dim_diameter_get_10_pt(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);

void   dwg_ent_dim_diameter_set_15_pt(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);
void   dwg_ent_dim_diameter_get_15_pt(dwg_ent_dim_diameter *dia, dwg_point_3d *point, int *error);

double dwg_ent_dim_diameter_get_leader_len(dwg_ent_dim_diameter *dia, int *error);
void   dwg_ent_dim_diameter_set_leader_len(dwg_ent_dim_diameter *dia, double leader_len, int *error);

//--------------------------------------------------------------------------------------

char   dwg_ent_endblk_get_dummy(dwg_ent_endblk *endblk, int *error);
void   dwg_ent_endblk_set_dummy(dwg_ent_endblk *endblk, char dummy, int *error);

char   dwg_ent_seqend_get_dummy(dwg_ent_seqend *seqend, int *error);
void   dwg_ent_seqend_set_dummy(dwg_ent_seqend *seqend, char dummy, int *error);

//-------------------------------------------------------------------------------------------

void   dwg_ent_shape_get_ins_pt(dwg_ent_shape *shape, dwg_point_3d *point, int *error);
void   dwg_ent_shape_set_ins_pt(dwg_ent_shape *shape, dwg_point_3d *point, int *error);

double dwg_ent_shape_get_scale(dwg_ent_shape *shape, int *error);
void   dwg_ent_shape_set_scale(dwg_ent_shape *shape, double scale, int *error);

double dwg_ent_shape_get_rotation(dwg_ent_shape *shape, int *error);
void   dwg_ent_shape_set_rotation(dwg_ent_shape *shape, double rotation, int *error);

double dwg_ent_shape_get_width_factor(dwg_ent_shape *shape, int *error);
void   dwg_ent_shape_set_width_factor(dwg_ent_shape *shape, double width_factor, int *error);

double dwg_ent_shape_get_oblique(dwg_ent_shape *shape, int *error);
void   dwg_ent_shape_set_oblique(dwg_ent_shape *shape, double oblique, int *error);

double dwg_ent_shape_get_thickness(dwg_ent_shape *shape, int *error);
void   dwg_ent_shape_set_thickness(dwg_ent_shape *shape, double thickness, int *error);

double dwg_ent_shape_get_shape_no(dwg_ent_shape *shape, int *error);
void   dwg_ent_shape_set_shape_no(dwg_ent_shape *shape, double no, int *error);

void   dwg_ent_shape_get_extrusion(dwg_ent_shape *shape, dwg_point_3d *point, int *error);
void   dwg_ent_shape_set_extrusion(dwg_ent_shape *shape, dwg_point_3d *point, int *error);

//-------------------------------------------------------------------------------------------

void dwg_ent_mtext_set_insertion_pt(dwg_ent_mtext *mtext, dwg_point_3d *point, int *error);
void dwg_ent_mtext_get_insertion_pt(dwg_ent_mtext *mtext, dwg_point_3d *point, int *error);

void dwg_ent_mtext_set_extrusion(dwg_ent_mtext *mtext, dwg_point_3d *point, int *error);
void dwg_ent_mtext_get_extrusion(dwg_ent_mtext *mtext, dwg_point_3d *point, int *error);

void dwg_ent_mtext_set_x_axis_dir(dwg_ent_mtext *mtext, dwg_point_3d *point, int *error);
void dwg_ent_mtext_get_x_axis_dir(dwg_ent_mtext *mtext, dwg_point_3d *point, int *error);

void dwg_ent_mtext_set_rect_height(dwg_ent_mtext *mtext, double rect_height, int *error);
double dwg_ent_mtext_get_rect_height(dwg_ent_mtext *mtext, int *error);

void dwg_ent_mtext_set_rect_width(dwg_ent_mtext *mtext, double rect_width, int *error);
double dwg_ent_mtext_get_rect_width(dwg_ent_mtext *mtext, int *error);

void dwg_ent_mtext_set_text_height(dwg_ent_mtext *mtext, double text_height, int *error);
double dwg_ent_mtext_get_text_height(dwg_ent_mtext *mtext, int *error);

unsigned int dwg_ent_mtext_get_attachment(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_attachment(dwg_ent_mtext *mtext, unsigned int attachment, int *error);

unsigned int dwg_ent_mtext_get_drawing_dir(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_drawing_dir(dwg_ent_mtext *mtext, unsigned int dir, int *error);

double dwg_ent_mtext_get_extends_ht(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_extends_ht(dwg_ent_mtext *mtext, double ht, int *error);

double dwg_ent_mtext_get_extends_wid(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_extends_wid(dwg_ent_mtext *mtext, double wid, int *error);

char* dwg_ent_mtext_get_text(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_text(dwg_ent_mtext *mtext, char * text, int *error);

unsigned int dwg_ent_mtext_linespace_style(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_linespace_style(dwg_ent_mtext *mtext, unsigned int style, int *error);

double dwg_ent_mtext_get_linespace_factor(dwg_ent_mtext *mtext, int *error);
void dwg_ent_mtext_set_linespace_factor(dwg_ent_mtext *mtext, double factor, int *error);

//-------------------------------------------------------------------------------------------

void dwg_ent_leader_set_annot_type(dwg_ent_leader *leader, unsigned int type, int *error);
unsigned int dwg_ent_leader_get_annot_type(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_path_type(dwg_ent_leader *leader, unsigned int type, int *error);
unsigned int dwg_ent_leader_get_path_type(dwg_ent_leader *leader, int *error);

long dwg_ent_leader_get_numpts(dwg_ent_leader *leader, int *error);
void dwg_ent_leader_set_numpts(dwg_ent_leader *leader, long numpts, int *error);

void dwg_ent_leader_set_end_pt_proj(dwg_ent_leader *leader, dwg_point_3d *point, int *error);
void dwg_ent_leader_get_end_pt_proj(dwg_ent_leader *leader, dwg_point_3d *point, int *error);

void dwg_ent_leader_set_extrusion(dwg_ent_leader *leader, dwg_point_3d *point, int *error);
void dwg_ent_leader_get_extrusion(dwg_ent_leader *leader, dwg_point_3d *point, int *error);

void dwg_ent_leader_set_x_direction(dwg_ent_leader *leader, dwg_point_3d *point, int *error);
void dwg_ent_leader_get_x_direction(dwg_ent_leader *leader, dwg_point_3d *point, int *error);

void dwg_ent_leader_set_offset_to_block_ins_pt(dwg_ent_leader *leader, dwg_point_3d *point, int *error);
void dwg_ent_leader_get_offset_to_block_ins_pt(dwg_ent_leader *leader, dwg_point_3d *point, int *error);

void dwg_ent_leader_set_dimgap(dwg_ent_leader *leader, double dimgap, int *error);
double dwg_ent_leader_get_dimgap(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_box_height(dwg_ent_leader *leader, double height, int *error);
double dwg_ent_leader_get_box_height(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_box_width(dwg_ent_leader *leader, double width, int *error);
double dwg_ent_leader_get_box_width(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_hook_line_on_x_dir(dwg_ent_leader *leader, char hook, int *error);
char dwg_ent_leader_get_hook_line_on_x_dir(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_arrowhead_on(dwg_ent_leader *leader, char arrow, int *error);
char dwg_ent_leader_get_arrowhead_on(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_arrowhead_type(dwg_ent_leader *leader, unsigned int type, int *error);
unsigned int dwg_ent_leader_get_arrowhead_type(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_dimasz(dwg_ent_leader *leader, double dimasz, int *error);
double dwg_ent_leader_get_dimasz(dwg_ent_leader *leader, int *error);

void dwg_ent_leader_set_byblock_color(dwg_ent_leader *leader, unsigned int color, int *error);
unsigned int dwg_ent_leader_get_byblock_color(dwg_ent_leader *leader, int *error);

//-------------------------------------------------------------------------------------------

void dwg_ent_tolerance_set_height(dwg_ent_tolerance *tol, double height, int *error);
double dwg_ent_tolerance_get_height(dwg_ent_tolerance *tol, int *error);

void dwg_ent_tolerance_set_dimgap(dwg_ent_tolerance *tol, double dimgap, int *error);
double dwg_ent_tolerance_get_dimgap(dwg_ent_tolerance *tol, int *error);

void dwg_ent_tolerance_set_ins_pt(dwg_ent_tolerance *tol, dwg_point_3d *point, int *error);
void dwg_ent_tolerance_get_ins_pt(dwg_ent_tolerance *tol, dwg_point_3d *point, int *error);

void dwg_ent_tolerance_set_x_direction(dwg_ent_tolerance *tol, dwg_point_3d *point, int *error);
void dwg_ent_tolerance_get_x_direction(dwg_ent_tolerance *tol, dwg_point_3d *point, int *error);

void dwg_ent_tolerance_set_extrusion(dwg_ent_tolerance *tol, dwg_point_3d *point, int *error);
void dwg_ent_tolerance_get_extrusion(dwg_ent_tolerance *tol, dwg_point_3d *point, int *error);

void dwg_ent_tolerance_set_text_string(dwg_ent_tolerance *tol, char * string, int *error);
char * dwg_ent_tolerance_get_text_string(dwg_ent_tolerance *tol, int *error);

//------------------------------------------------------------------------------------

dwg_obj_block_header * dwg_get_block_header(Dwg_Data *dwg, int *error);

//--------------------------------------------------------------------------------

dwg_obj_block_control* dwg_block_header_get_block_control(dwg_obj_block_header* block_header, int *error);

//--------------------------------------------------------------------------------

// Get Layer Name
char * dwg_obj_layer_get_name(dwg_obj_layer *layer, int *error);

//--------------------------------------------------------------------------------

// Get Block Name
char * dwg_obj_block_header_get_name(dwg_obj_block_header *hdr, int *error);

#endif
