#ifndef __VECTOR_3_H__
#define __VECTOR_3_H__
#include <cmath>

class Vector3 {
public:
    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    // Normaliza o vetor para que tenha magnitude igual a 1

    float magnitude() const {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }

    void normalize() {
        float mg = magnitude();
        if (mg != 0) {
            x /= mg;
            y /= mg;
            z /= mg;
        }
    }

    // Calcula a distância entre dois vetores
    float distance(const Vector3& other) const {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Sobrecarga do operador de adição
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    // Sobrecarga do operador de subtração
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    // Calcula o produto interno entre dois vetores
    float dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    Vector3 cross(const Vector3& other) const {
        float resultX = y * other.z - z * other.y;
        float resultY = z * other.x - x * other.z;
        float resultZ = x * other.y - y * other.x;
        return Vector3(resultX, resultY, resultZ);
    }

    
};

#endif
