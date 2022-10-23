/**
 * @file: trapezoid.h
 * @type: C++ (header file)
 * @date: 10_MARCH_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * If trapezoid.h has not already been linked to a source file (.cpp), 
 * then link this header file to the source file(s) which include this header file.
 */
#ifndef TRAPEZOID_H 
#define TRAPEZOID_H

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the QUADRILATERAL class.
 */
#include "quadrilateral.h" 

/**
 * TRAPEZOID is a class which inherits the protected and public data attributes
 * and protected and public data attributes of the QUADRILATERAL class.
 * 
 * QUADRILATERAL is a class which inherits the protected and public data
 * attributes and methods of POLYGON (and POLYGON is an abstract class).
 * 
 * A TRAPEZOID object represents a non-degenerate four-sided polygon with exactly two parallel sides.
 * 
 * The public keyword prefacing QUADRILATERAL in the class definition below specifies that
 * all the public members of the parent class QUADRILATERAL will be public in the child class TRAPEZOID
 * and that all the protected members of the parent class QUADRILATERAL will be protected in the child class TRAPEZOID.
 * 
 * If the access specifier prefacing QUADRILATERAL in the class definition below is protected instead of public, then
 * all the public members of the parent class QUADRILATERAL will be protected in the child class TRAPEZOID
 * and all the protected members of the parent class QUADRILATERAL will be protected in the child class TRAPEZOID.
 * 
 * If the access specifier prefacing QUADRILATERAL in the class definition below is private instead of public, then
 * all the public members of the parent class QUADRILATERAL will be private in the child class TRAPEZOID
 * and all the protected members of the parent class QUADRILATERAL will be private in the child class TRAPEZOID.
 */
class TRAPEZOID: public QUADRILATERAL
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a const (i.e. const (i.e. immutable)) value.
     */
    const std::string category = "POLYGON/QUADRILATERAL/TRAPEZOID";

    /**
     * Determine whether or not point_0, point_1, point_2, and point_3 collectively 
     * form a valid trapezoid.
     * 
     * A valid trapezoid is a non-degenerate quadrilateral whose interior angle measurements
     * add up to 360 degrees such that exactly two opposite sides are parallel to each other.
     * 
     * A degenerate quadrilateral is a quadrilateral whose area is zero (due to the fact that one line 
     * intersects each of the four points).
     * 
     * If each of the input point values represent a valid trapezoid, then return true.
     * 
     * Otherwise, return false.
     */
    bool points_form_valid_trapezoid(POINT point_0, POINT point_1, POINT point_2, POINT point_3);
    
public:
    
    /**
     * The default constructor of TRAPEZOID calls QUADRILATERAL's constructor
     * and sets color to "orange" and trapezoid points to
     * A(0,0), B(1,1), C(2,1), and D(3,0).
     */
    TRAPEZOID();
    
    /**
     * The normal constructor of TRAPEZOID attempts to set
     * the color and point values to the input values.
     * 
     * If those point values fail to represent a valid trapezoid,
     * then set the point values to the coordinates of the default
     * trapezoid points.
     */
    TRAPEZOID(std::string color, POINT A, POINT B, POINT C, POINT D);
    
    /**
     * The copy constructor of TRAPEZOID creates a clone of 
     * the input TRAPEZOID instance.
     */
    TRAPEZOID(TRAPEZOID & trapezoid); 

    /** 
     * This method overrides QUADRILATERAL's print method.
     * 
     * The descriptor method prints a description of the caller TRAPEZOID to the output stream.
     * If no parameter is supplied, output is set to the command line.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the TRAPEZOID class,
     * but it does have access to the members of TRAPEZOID as though
     * it were a member of that class.
     */
    friend std::ostream & operator << (std::ostream & output, TRAPEZOID & trapezoid);
};

/**
 * End of header file
 */
#endif