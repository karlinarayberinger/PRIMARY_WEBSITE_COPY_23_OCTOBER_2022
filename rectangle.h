/**
 * @file: rectangle.h
 * @type: C++ (header file)
 * @date: 15_MARCH_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * If rectangle.h has not already been linked to a source file (.cpp), 
 * then link this header file to the source file(s) which include this header file.
 */
#ifndef RECTANGLE_H 
#define RECTANGLE_H

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the QUADRILATERAL class.
 */
#include "quadrilateral.h" 

/**
 * RECTANGLE is a class which inherits the protected and public data attributes
 * and protected and public data attributes of the QUADRILATERAL class.
 * 
 * QUADRILATERAL is a class which inherits the protected and public data
 * attributes and methods of POLYGON (and POLYGON is an abstract class).
 * 
 * A RECTANGLE object represents a non-degenerate four-sided polygon whose interior angles each 
 * have an angle measurement of exactly 90 degrees.
 * 
 * Note that 90 degrees is (PI/2) radians.
 *
 * The public keyword prefacing QUADRILATERAL in the class definition below specifies that
 * all the public members of the parent class QUADRILATERAL will be public in the child class RECTANGLE
 * and that all the protected members of the parent class QUADRILATERAL will be protected in the child class RECTANGLE.
 * 
 * If the access specifier prefacing QUADRILATERAL in the class definition below is protected instead of public, then
 * all the public members of the parent class QUADRILATERAL will be protected in the child class RECTANGLE
 * and all the protected members of the parent class QUADRILATERAL will be protected in the child class RECTANGLE.
 * 
 * If the access specifier prefacing QUADRILATERAL in the class definition below is private instead of public, then
 * all the public members of the parent class QUADRILATERAL will be private in the child class RECTANGLE
 * and all the protected members of the parent class QUADRILATERAL will be private in the child class RECTANGLE.
 */
class RECTANGLE: public QUADRILATERAL
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a const (i.e. const (i.e. immutable)) value.
     */
    const std::string category = "POLYGON/QUADRILATERAL/RECTANGLE";

    /**
     * Determine whether or not point_0, point_1, point_2, and point_3 collectively 
     * form a valid rectangle.
     * 
     * A valid rectangle is a non-degenerate quadrilateral whose interior angle measurements
     * are each exactly 90 degrees (i.e. (PI/2) radians).
     * 
     * A degenerate quadrilateral is a quadrilateral whose area is zero (due to the fact that one line 
     * intersects each of the four points).
     * 
     * If each of the input point values represent a valid rectangle, then return true.
     * 
     * Otherwise, return false.
     */
    bool points_form_valid_rectangle(POINT point_0, POINT point_1, POINT point_2, POINT point_3);
    
public:
    
    /**
     * The default constructor of RECTANGLE calls QUADRILATERAL's constructor
     * and sets color to "orange" and rectangle points to
     * A(0,0), B(0,2), C(6,2), and D(6,0).
     */
    RECTANGLE();
    
    /**
     * The normal constructor of RECTANGLE attempts to set
     * the color and point values to the input values.
     * 
     * If those point values fail to represent a valid rectangle,
     * then set the point values to the coordinates of the default
     * rectangle points.
     */
    RECTANGLE(std::string color, POINT A, POINT B, POINT C, POINT D);
    
    /**
     * The copy constructor of RECTANGLE creates a clone of 
     * the input RECTANGLE instance.
     */
    RECTANGLE(RECTANGLE & rectangle); 

    /** 
     * This method overrides QUADRILATERAL's print method.
     * 
     * The descriptor method prints a description of the caller RECTANGLE to the output stream.
     * If no parameter is supplied, output is set to the command line.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the RECTANGLE class,
     * but it does have access to the members of RECTANGLE as though
     * it were a member of that class.
     */
    friend std::ostream & operator << (std::ostream & output, RECTANGLE & rectangle);
};

/**
 * End of header file
 */
#endif