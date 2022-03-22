#ifndef RAYLIB_CPP_INCLUDE_RAYCOLLISION_HPP_
#define RAYLIB_CPP_INCLUDE_RAYCOLLISION_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Raycast hit information
 */
class RayCollision : public ::RayCollision {
 public:
    RayCollision(const ::RayCollision& ray) {
        set(ray);
    }

    RayCollision(bool hit, float distance,
        ::Vector3 point, ::Vector3 normal) : ::RayCollision{hit, distance, point, normal} {
        // Nothing.
    }

    /**
     * Get collision info between ray and mesh
     */
    RayCollision(const ::Ray& ray, const ::Mesh& mesh, const ::Matrix& transform) {
        set(::GetRayCollisionMesh(ray, mesh, transform));
    }

    /**
     * Get collision info between ray and model
     */
    RayCollision(const ::Ray& ray, const ::Model& model) {
        set(::GetRayCollisionModel(ray, model));
    }

    /**
     * Get collision info between ray and triangle
     */
    RayCollision(const ::Ray& ray, ::Vector3 p1, ::Vector3 p2, ::Vector3 p3) {
        set(::GetRayCollisionTriangle(ray, p1, p2, p3));
    }

    RayCollision& operator=(const ::RayCollision& ray) {
        set(ray);
        return *this;
    }

    GETTERSETTER(bool, Hit, hit)
    GETTERSETTER(float, Distance, distance)
    GETTERSETTER(::Vector3, Position, point)
    GETTERSETTER(::Vector3, Normal, normal)

 private:
    inline void set(const ::RayCollision& ray) {
        hit = ray.hit;
        distance = ray.distance;
        point = ray.point;
        normal = ray.normal;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAYCOLLISION_HPP_
