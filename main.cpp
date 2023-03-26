#include <iostream>
#include <cmath>
#include <string>

struct Vector {
    double x, y;

    Vector(double v_x = 0, double v_y = 0) {
        x = v_x;
        y = v_y;
    }
};

Vector add(Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y);
}

Vector subtract(Vector a, Vector b) {
    return Vector(a.x - b.x, a.y - b.y);
}

Vector scale(Vector a, double scalar) {
    return Vector(a.x * scalar, a.y * scalar);
}

double length(Vector a) {
    return sqrt(std::abs(a.x * a.x + a.y * a.y));
}

Vector normalize(Vector a) {
    double len = length(a);
    if (len != 0) {
        return Vector(a.x / len, a.y / len);
    } else {
        return Vector(0, 0);
    }
}

int main() {
    std::string operation;
    std::cin >> operation;
    Vector a, b;
    double scalar;
    std::cin >> a.x >> a.y;
    if (operation == "add" || operation == "subtract") {
        std::cin >> b.x >> b.y;
    } else if (operation == "scale") {
        std::cin >> scalar;
    }

    if (operation == "add") {
        Vector result = add(a, b);
        std::cout << result.x << " " << result.y << std::endl;
    } else if (operation == "subtract") {
        Vector result = subtract(a, b);
        std::cout << result.x << " " << result.y << std::endl;
    } else if (operation == "scale") {
        Vector result = scale(a, scalar);
        std::cout << result.x << " " << result.y << std::endl;
    } else if (operation == "length") {
        double result = length(a);
        std::cout << result << std::endl;
    } else if (operation == "normalize") {
        Vector result = normalize(a);
        std::cout << result.x << " " << result.y << std::endl;
    } else {
        std::cout << "Invalid operation" << std::endl;
    }

    return 0;
}
