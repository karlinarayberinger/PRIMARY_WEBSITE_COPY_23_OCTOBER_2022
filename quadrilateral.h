/**
 * @file: quadrilateral.h
 * @type: C++ (header file)
 * @date: 01_AUGUST_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * If quadrilateral.h has not already been linked to a source file (.cpp), 
 * then link this header file to the source file(s) which include this header file.
 */
#ifndef QUADRILATERAL_H 
#define QUADRILATERAL_H

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the POLYGON class.
 */
#include "polygon.h" 

/**
 * QUADRILATERAL is a class which inherits the protected and public data
 * attributes and the public and protected methods of the POLYGON class
 * (and POLYGON is an abstract class).
 * 
 * A QUADRILATERAL object represents a non-degenerate four-sided polygon.
 * 
 * (A non-degenerate polygon has a positive area. A degenerate polygon is visually depicted as a line segment).
 * 
 * The public keyword prefacing POLYGON in the class definition below specifies that
 * all the public members of the base class POLYGON will be public in the derived class QUADRILATERAL
 * and that all the protected members of the base class POLYGON will be protected in the derived class QUADRILATERAL.
 * 
 * If the access specifier prefacing POLYGON in the class definition below is protected instead of public, then
 * all the public members of the base class POLYGON will be protected in the derived class QUADRILATERAL
 * and all the protected members of the base class POLYGON will be protected in the derived class QUADRILATERAL.
 * 
 * If the access specifier prefacing POLYGON in the class definition below is private instead of public, then
 * all the public members of the base class POLYGON will be private in the derived class QUADRILATERAL
 * and all the protected members of the base class POLYGON will be private in the derived class QUADRILATERAL.
 */
class QUADRILATERAL: public POLYGON
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a const (i.e. const (i.e. immutable)) value.
     */
    const std::string category = "POLYGON/QUADRILATERAL";

    /**
     * A, B, C, and D represent unique coordinate pairs which are plotted on the same Cartesian plane.
     */
    POINT A, B, C, D;

    /**
     * Determine whether or not point_0, point_1, point_2, and point_3 each represent unique coordinate pairs.
     * 
     * (Assume that point_0, point_1, point_2, and point_3 each represent valid POINT instances).
     * 
     * If each of the four POINT objects represent unique coordinate pairs, then return true.
     * 
     * Otherwise, return false.
     */
    bool points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2, POINT point_3);

    /**
     * Determine whether or not point_0, point_1, point_2, and point_3 collectively 
     * form a non-degenerate quadrilateral.
     * 
     * (Assume that point_0, point_1, point_2, and point_3 each represent valid POINT instances).
     * 
     * A non-degenerate quadrilateral is a quadrilateral whose area is some positive real number quantity.
     * 
     * A degenerate quadrilateral is a quadrilateral whose area is zero (due to the fact that one line 
     * intersects each of the four points).
     * 
     * If each of the four POINT objects represent a non-degenerate quadrilateral, then return true.
     * 
     * If each of the four interior angles of the QUADRILATERAL whose POINT values are identical to the parameters sum up to 360 degrees,
     * then return true. (This is to ensure that the quadrilateral does not resemble a six-sided "bow tie" shaped polygon comprised of two non-overlapping triangles).
     * 
     * Otherwise, return false.
     */
    bool points_form_nondegenerate_quadrilateral(POINT point_0, POINT point_1, POINT point_2, POINT point_3);
    
public:
    
    /**
     * The default constructor of QUADRILATERAL calls POLYGON's constructor
     * and sets color to "orange" and quadrilateral points to
     * A(0,0), B(0,5), C(6,8), and D(3,0).
     */
    QUADRILATERAL();
    
    /**
     * The normal constructor of QUADRILATERAL attempts to set
     * the color and point values to the input values.
     * 
     * (Assume that inputs A, B, C, and D each represent valid POINT instances).
     * 
     * If those point values fail to represent a non-degenerate quadrilateral,
     * then set the point values to the coordinates of the default
     * quadrilateral points.
     */
    QUADRILATERAL(std::string color, POINT A, POINT B, POINT C, POINT D);
    
    /**
     * The copy constructor of QUADRILATERAL creates a clone of 
     * the input QUADRILATERAL instance.
     * 
     * (Assume that quadrilateral represents a valid QUADRILATERAL instance).
     */
    QUADRILATERAL(QUADRILATERAL & quadrilateral);

    /** 
     * The getter method of the QUADRILATERAL class named get_A() returns 
     * the value of the caller QUADRILATERAL object's A property.
     */
    POINT get_A();

    /** 
     * The getter method of the QUADRILATERAL class named get_B() returns 
     * the value of the caller QUADRILATERAL object's B property.
     */
    POINT get_B();  

    /** 
     * The getter method of the QUADRILATERAL class named get_C() returns 
     * the value of the caller QUADRILATERAL object's C property.
     */
    POINT get_C();

    /** 
     * The getter method of the QUADRILATERAL class named get_D() returns 
     * the value of the caller QUADRILATERAL object's D property.
     */
    POINT get_D();   

    /** 
     * The getter method of the QUADRILATERAL class named get_side_length_AB() 
     * returns the length of the shortest path between points A and B.
     */
    double get_side_length_AB();

    /** 
     * The getter method of the QUADRILATERAL class named get_side_length_BC() 
     * returns the length of the shortest path between points B and C.
     */
    double get_side_length_BC();

    /** 
     * The getter method of the QUADRILATERAL class named get_side_length_CD() 
     * returns the length of the shortest path between points C and D.
     */
    double get_side_length_CD();

    /** 
     * The getter method of the QUADRILATERAL class named get_side_length_DA() 
     * returns the length of the shortest path between points D and A.
     */
    double get_side_length_DA();

    /** 
     * The getter method of the QUADRILATERAL class named get_diagonal_length_AC() 
     * returns the length of the shortest path between points A and C.
     */
    double get_diagonal_length_AC();

    /** 
     * The getter method of the QUADRILATERAL class named get_diagonal_length_BD() 
     * returns the length of the shortest path between points B and D.
     */
    double get_diagonal_length_BD();

    /**
     * The getter method of the QUADRILATERAL class named get_interior_angle_ABC() 
     * returns the angle measurement in degrees of the angle
     * formed by connecting points A, B, anc C in that order.
     * 
     * This function uses Law of Cosines to compute the angle measurement of an angle 
     * given that triangle's side lengths as function inputs 
     * (and the triangle is the area bound between the line segments 
     * which connect points A, B, and C).
     */
    double get_interior_angle_ABC();

    /**
     * The getter method of the QUADRILATERAL class named get_interior_angle_BCD() 
     * returns the angle measurement in degrees of the angle
     * formed by connecting points B, C, and D in that order.
     * 
     * This function uses Law of Cosines to compute the angle measurement of an angle 
     * given that triangle's side lengths as function inputs 
     * (and the triangle is the area bound between the line segments 
     * which connect points B, C, and D).
     */
    double get_interior_angle_BCD();

    /**
     * The getter method of the QUADRILATERAL class named get_interior_angle_CDA() 
     * returns the angle measurement in degrees of the angle
     * formed by connecting points C, D, and A in that order.
     * 
     * This function uses Law of Cosines to compute the angle measurement of an angle 
     * given that triangle's side lengths as function inputs 
     * (and the triangle is the area bound between the line segments 
     * which connect points C, D, and A).
     */
    double get_interior_angle_CDA();

    /**
     * The getter method of the QUADRILATERAL class named get_interior_angle_DAB() 
     * returns the angle measurement in degrees of the angle
     * formed by connecting points D, A, and B in that order.
     * 
     * This function uses Law of Cosines to compute the angle measurement of an angle 
     * given that triangle's side lengths as function inputs 
     * (and the triangle is the area bound between the line segments 
     * which connect points D, A, and B).
     */
    double get_interior_angle_DAB();

    /**
     * The QUADRILATERAL class implements the virtual get_area() method of the POLYGON class.
     * 
     * The getter returns the area of the quadrilateral using using Heron's Formula to 
     * compute the area of each of the two triangles which comprise that quadrilateral.
     * 
     * Let d be the length of the line segment whose endpoints are A and B.
     * Let a be the length of the line segment whose endpoints are B and C.
     * Let e be the length of the line segment whose endpoints are C and A.
     * Let f be the length of the line segment whose endpoints are B and D.
     * Let b be the length of the line segment whose endpoints are C and D.
     * Let c be the length of the line segment whose endpoints are D and A.
     * 
     * Let the first triangle be the area which is enclosed inside line segments named d, a, and e.
     * 
     * Let the second triangle be the area which is enclosed inside line segments named c, b, and e.
     * 
     * Then compute the area of the first triangle using Heron's Formula as follows:
     * 
     * Let s0 be the semiperimeter of the first triangle (i.e. the perimeter of the first triangle divided by 2). 
     * 
     * Hence, 
     * 
     * s0 := (d + a + e) / 2.
     * 
     * Then the area of the first triangle is 
     * 
     * first_triangle_area := square_root( s0 * (s0 - d) * (s0 - a) * (s0 - e) ).
     * 
     * Then compute the area of the second triangle using Heron's Formula as follows:
     * 
     * Let s1 be the semiperimeter of the second triangle (i.e. the perimeter of the second triangle divided by 2). 
     * 
     * Hence, 
     * 
     * s1 := (c + b + e) / 2.
     * 
     * Then the area of the second triangle is 
     * 
     * second_triangle_area := square_root( s1 * (s1 - c) * (s1 - b) * (s1 - e) ).
     * 
     * Finally, return the sum of first_triangle_area and second_triangle_area.
     */
    double get_area();

    /**
     * The QUADRILATERAL class implements the virtual get_perimeter() method of the POLYGON class.
     * 
     * Let d be the length of the line segment whose endpoints are A and B.
     * Let a be the length of the line segment whose endpoints are B and C.
     * Let b be the length of the line segment whose endpoints are C and D.
     * Let c be the length of the line segment whose endpoints are D and A.
     * 
     * Then return the sum of a, b, c, and d.
     */
    double get_perimeter();
    
    /** 
     * This method overrides POLYGON's print method.
     * 
     * The descriptor method prints a description of the caller QUADRILATERAL to the output stream.
     * If no parameter is supplied, output is set to the command line.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the QUADRILATERAL class,
     * but it does have access to the members of QUADRILATERAL as though
     * it were a member of that class.
     */
    friend std::ostream & operator << (std::ostream & output, QUADRILATERAL & quadrilateral);
};

/**
 * End of header file
 */
#endif