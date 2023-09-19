#ifndef ADVANCED_CPP_BHCC_SHAPE_H
#define ADVANCED_CPP_BHCC_SHAPE_H

/**
 * Strongly typed color.
 */
enum class Color {
    RED,
    GREEN,
    BLUE
};

/**
 * A virtual shape class.
 */
class Shape {
public:
    explicit Shape(std::string_view name) : name(name), color(Color::RED) {}

    /**
     * Rotates the shape in specified degrees.
     * @param degrees The degrees to rotate.
     */
    void rotate(int degrees) {
        std::cout << name << " is rotated " << degrees << " degrees." << std::endl;
    }

    /**
     * This shape plays sounds.
     */
    virtual void playSound() = 0;

    /**
     * Returns the name of this shape.
     */
    std::string_view getName() {
        return name;
    }

    /**
     * Returns the color of this shape.
     * @return
     */
    Color getColor() { return color; }

    /**
     * Sets the color of this shape.
     * @param color The color to set.
     */
    void setColor(Color _color) {
        color = _color;
    }

protected:
    // The name of this shape
    std::string_view name;

    // The color of this shape.
    Color color;
};

#endif
