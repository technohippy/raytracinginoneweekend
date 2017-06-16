#ifndef CAMERAH
#define CAMERAH

#include "ray.h"

class camera {
  public:
    camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect) { // vfov is top to bottom in degrees
      vec3 u, v, w;
      float theta = vfov*M_PI/180;
      float half_height = tan(theta/2);
      float half_width = aspect * half_height;
      origin = lookfrom;
      w = unit_vector(lookfrom - lookat);
      u = unit_vector(cross(vup, w));
      v = cross(w, u);
      /*
      lower_left_corner = vec3(-half_width, -half_height, -1.0);
      horizontal = vec3(2*half_width, 0.0, 0.0);
      vertical = vec3(0.0, 2*half_height, 0.0);
      */
      lower_left_corner = origin - half_width*u - half_height*v - w;
      horizontal = 2*half_width*u;
      vertical = 2*half_height*v;
    }
    //ray get_ray(float u, float v) { return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin); }
    ray get_ray(float s, float t) { return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin); }

    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};

#endif
