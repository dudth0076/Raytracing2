#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"
#include "Vec3.h"

class Sphere : public Hittable
{
public:
    Sphere(const Point3& center, double radius)
        : mCenter(center), mRadius(std::fmax(0.0, radius))
    {
    }
    bool Hit(
        const Ray& ray,
        const Interval& rayT,
        HitRecord& hitRecord
    ) const override
    {
        Vec3 originToCenter = mCenter - ray.Origin();

        auto a = ray.Direction().LengthSquared();
        auto h = Dot(ray.Direction(), originToCenter);
        auto c = originToCenter.LengthSquared() - mRadius * mRadius;

        auto discriminant = h * h - a * c;
        if (discriminant < 0.0)
        {
            return false;
        }

        auto squareRootDiscriminant = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range
            // 허용 가능한 범위 내에 있는 가장 가까운 근을 찾습니다
            auto root = (h - squareRootDiscriminant) / a;
        if (!rayT.Surrounds(root))
        {
            root = (h + squareRootDiscriminant) / a;
            if (!rayT.Surrounds(root))
            {
                return false;
            }
        }

        hitRecord.T = root;
        hitRecord.point = ray.At(hitRecord.T);

        Vec3 outwardNormal = (hitRecord.point - mCenter) / mRadius;
        hitRecord.SetFaceNormal(ray, outwardNormal);

        return true;
    }

private:
    Point3 mCenter;
    double mRadius = 0.0;
};
#endif