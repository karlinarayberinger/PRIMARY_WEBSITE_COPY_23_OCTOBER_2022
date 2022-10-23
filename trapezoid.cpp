/**
 * @file: trapezoid.cpp
 * @type: C++ (source file)
 * @date: 12_MARCH_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the TRAPEZOID class.
 */
#include "trapezoid.h" 

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
bool TRAPEZOID::points_form_valid_trapezoid(POINT point_0, POINT point_1, POINT point_2, POINT point_3)
{
    if (!points_form_nondegenerate_quadrilateral(point_0, point_1, point_2, point_3))
    {
        std::cout << "\n\npoints_form_nondegenerate_quadrilateral(point_0, point_1, point_2, point_3) returned false.";
        std::cout << "\nHence, points_form_valid_trapezoid(point_0, point_1, point_2, point_3) is returning false.";
        return false;
    }
    A = point_0;
    B = point_1;
    C = point_2;
    D = point_3;
    /**
     * // The line segment whose endpoints are B and C is parallel to the line segment whose endpoints are A and D.
     * // The line segment whose endpoints are A and B is not parallel to the line segment whose endpoints are C and D.
     * 
     *      B     C
     * 
     * 
     *  A             D     
     */
    if ((floor(get_interior_angle_DAB()) == floor(get_interior_angle_CDA())) && (floor(get_interior_angle_ABC()) == floor(get_interior_angle_BCD())) && (floor(get_interior_angle_DAB()) != floor(get_interior_angle_BCD()))) return true;
    /**
     * // The line segment whose endpoints are A and B is parallel to the line segment whose endpoints are D and C.
     * // The line segment whose endpoints are D and A is not parallel to the line segment whose endpoints are B and C.
     * 
     *      A     B
     * 
     * 
     *  D             C     
     */
    if ((floor(get_interior_angle_CDA()) == floor(get_interior_angle_BCD())) && (floor(get_interior_angle_DAB()) == floor(get_interior_angle_ABC())) && (floor(get_interior_angle_CDA()) != floor(get_interior_angle_ABC()))) return true;
    std::cout << "\n\nExactly two opposite sides of the quadrilateral are required to be parallel to each other in order for that quadrilateral to be a valid trapezoid.";
    std::cout << "\nA := POINT(" << A.get_X() << ", " << A.get_Y() << "). // point_0";
    std::cout << "\nB := POINT(" << B.get_X() << ", " << B.get_Y() << "). // point_1";
    std::cout << "\nC := POINT(" << C.get_X() << ", " << C.get_Y() << "). // point_2";
    std::cout << "\nD := POINT(" << D.get_X() << ", " << D.get_Y() << "). // point_3";
    std::cout << "\nget_interior_angle_DAB() = " << get_interior_angle_DAB() << ".";
    std::cout << "\nget_interior_angle_ABC() = " << get_interior_angle_ABC() << ".";
    std::cout << "\nget_interior_angle_BCD() = " << get_interior_angle_BCD() << ".";
    std::cout << "\nget_interior_angle_CDA() = " << get_interior_angle_CDA() << ".";
    std::cout << "\nHence, points_form_valid_trapezoid(point_0, point_1, point_2, point_3) is returning false.";
    return false;
}

/**
 * The default constructor of TRAPEZOID calls QUADRILATERAL's constructor
 * and sets color to "orange" and trapezoid points to
 * A(0,0), B(1,1), C(2,1), and D(3,0).
 */
TRAPEZOID::TRAPEZOID()
{
    A = POINT(0,0);
    B = POINT(1,1);
    C = POINT(2,1);
    D = POINT(3,0);
}
    
/**
 * The normal constructor of TRAPEZOID attempts to set
 * the color and point values to the input values.
 * 
 * If those point values fail to represent a valid trapezoid,
 * then set the point values to the coordinates of the default
 * trapezoid points.
 */
TRAPEZOID::TRAPEZOID(std::string color, POINT A, POINT B, POINT C, POINT D)
{
    this -> color = color;
    if (!points_form_valid_trapezoid(A, B, C, D))
    {
        this -> A = POINT(0,0);
        this -> B = POINT(1,1);
        this -> C = POINT(2,1);
        this -> D = POINT(3,0);
        return;
    }
    this -> A = POINT(A);
    this -> B = POINT(B);
    this -> C = POINT(C);
    this -> D = POINT(D);
}
    
/**
 * The copy constructor of TRAPEZOID creates a clone of 
 * the input TRAPEZOID instance.
 */
TRAPEZOID::TRAPEZOID(TRAPEZOID & trapezoid)
{
    A = trapezoid.A;
    B = trapezoid.B;
    C = trapezoid.C;
    D = trapezoid.D;
    color = trapezoid.color;
}

/** 
 * This method overrides QUADRILATERAL's print method.
 * 
 * The descriptor method prints a description of the caller TRAPEZOID to the output stream.
 * If no parameter is supplied, output is set to the command line.
 */
void TRAPEZOID::print(std::ostream & output)
{
    output << "\n\n---------------------";
    output << "\nmemory_address := " << this << ". // address of first byte-sized memory cell in a TRAPEZOID-object-sized block of such memory cells";
    output << "\ncategory := " << category << ".";
    output << "\ncolor := " << color << ".";
    output << "\nA := POINT(" << A.get_X() << ", " << A.get_Y() << "). // POINT-type object whose data attributes are two int-type variable";
    output << "\nB := POINT(" << B.get_X() << ", " << B.get_Y() << "). // POINT-type object whose data attributes are two int-type variables";
    output << "\nC := POINT(" << C.get_X() << ", " << C.get_Y() << "). // POINT-type object whose data attributes are two int-type variables";
    output << "\nD := POINT(" << D.get_X() << ", " << D.get_Y() << "). // POINT-type object whose data attributes are two into-type variables";
    output << "\nd := get_side_length_AB() = " << get_side_length_AB() << ". // sum of Cartesian grid unit square side lengths equal to the length of the shortest path between A and B";
    output << "\na := get_side_length_BC() = " << get_side_length_BC() << ". // sum of Cartesian grid unit square side lengths equal to the length of the shortest path between B and C";
    output << "\nb := get_side_length_CD() = " << get_side_length_CD() << ". // sum of Cartesian grid unit square side lengths equal to the length of the shortest path between C and D";
    output << "\nc := get_side_length_DA() = " << get_side_length_DA() << ". // sum of Cartesian grid unit square side lengths equal to the length of the shortest path between D and A";
    output << "\ne := get_diagonal_length_AC() = " << get_diagonal_length_AC() << ". // sum of Cartesian grid unit square side lengths equal to the length of the shortest path between A and C";
    output << "\nf := get_diagonal_length_BD() = " << get_diagonal_length_BD() << ". // sum of Cartesian grid unit square side lengths equal to the length of the shortestt path between B and D";
    output << "\nget_interior_angle_ABC() = " << get_interior_angle_ABC() << ". // degrees and not radians of interior angle whose pivot point is B";
    output << "\nget_interior_angle_BCD() = " << get_interior_angle_BCD() << ". // degrees and not radians of interior angle whose pivot point is C";
    output << "\nget_interior_angle_CDA() = " << get_interior_angle_CDA() << ". // degrees and not radians of interior angle whose pivot point is D";
    output << "\nget_interior_angle_DAB() = " << get_interior_angle_DAB() << ". // degrees and not radians of interior angle whose pivot point is A";
    output << "\nget_area() = " << get_area() << ". // sum of Cartesian grid unit square areas bound by line segments a, b, c, and d";
    output << "\nget_perimeter() = " << get_perimeter() << ". // sum of Cartesian grid unit square side lengths equal to the sum of the lengths of line segments a, b, c, and d";
    output << "\n---------------------";
}
    
/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the TRAPEZOID class,
 * but it does have access to the members of TRAPEZOID as though
 * it were a member of that class.
 */
std::ostream & operator << (std::ostream & output, TRAPEZOID & trapezoid)
{
    trapezoid.print(output);
    return output;
}