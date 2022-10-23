/**
 * @file: quadrilateral.cpp
 * @type: C++ (source file)
 * @date: 07_AUGUST_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the QUADRILATERAL class.
 */
#include "quadrilateral.h" 

/**
 * Determine whether or not point_0, point_1, point_2, and point_3 each represent unique coordinate pairs.
 * 
 * If each of the four POINT objects represent unique coordinate pairs, then return true.
 * 
 * Otherwise, return false.
 * 
 * (Assume that point_0, point_1, point_2, and point_3 each represent valid POINT instances).
 */
bool QUADRILATERAL::points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2, POINT point_3)
{
    if ((point_0.get_X() == point_1.get_X()) && (point_0.get_Y() == point_1.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_1 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        return false;
    }
    if ((point_0.get_X() == point_2.get_X()) && (point_0.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_0.get_X() == point_3.get_X()) && (point_0.get_Y() == point_3.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_3 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_3 := POINT(" << point_3.get_X() << ", " << point_3.get_Y() << ").";
        return false;
    }
    if ((point_1.get_X() == point_2.get_X()) && (point_1.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_1 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_1.get_X() == point_3.get_X()) && (point_1.get_Y() == point_3.get_Y())) 
    {
        std::cout << "\n\npoint_1 and point_3 appear to represent the same coordinate pair.";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        std::cout << "\npoint_3 := POINT(" << point_3.get_X() << ", " << point_3.get_Y() << ").";
        return false;
    }
    if ((point_2.get_X() == point_0.get_X()) && (point_2.get_Y() == point_0.get_Y())) 
    {
        std::cout << "\n\npoint_2 and point_0 appear to represent the same coordinate pair.";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        return false;
    }
    if ((point_2.get_X() == point_3.get_X()) && (point_2.get_Y() == point_3.get_Y())) 
    {
        std::cout << "\n\npoint_2 and point_3 appear to represent the same coordinate pair.";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        std::cout << "\npoint_3 := POINT(" << point_3.get_X() << ", " << point_3.get_Y() << ").";
        return false;
    }
    return true;
}

/**
 * Determine whether or not point_0, point_1, point_2, and point_3 collectively 
 * form a non-degenerate quadrilateral.
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
bool QUADRILATERAL::points_form_nondegenerate_quadrilateral(POINT point_0, POINT point_1, POINT point_2, POINT point_3)
{
    double sum_of_interior_angle_measurements = 0.0;
    if (!points_represent_unique_coordinate_pairs(point_0, point_1, point_2, point_3)) 
    {
        std::cout << "\n\npoint_0, point_1, point_2, and point_3 do not each represent unique coordinate pairs.";
        std::cout << "\nHence, points_represent_unique_coordinate_pairs(point_0, point_1, point_2, point_3) is returning false.";
        return false;
    }
    A = point_0;
    B = point_1;
    C = point_2;
    D = point_3;
    if (get_area() <= 0) 
    {
        std::cout << "\n\nWhen setting the POINT values of the caller QUADRILATERAL object to the function parameters, get_area() returned a non-positive number result.";
        std::cout << "\nHence, points_form_nondegenerate_quadrilateral(POINT point_0, POINT point_1, POINT point_2, POINT point_3) is returning false.";
        return false;
    }
    sum_of_interior_angle_measurements = get_interior_angle_ABC() + get_interior_angle_BCD() + get_interior_angle_CDA() + get_interior_angle_DAB();
    if ((sum_of_interior_angle_measurements > 361) || (sum_of_interior_angle_measurements < 359))
    {
        std::cout << "\n\nWhen setting the POINT values of the caller QUADRILATERAL object to the function parameters, the sum of the interior angles did not add up to 360 degrees with no more than 1 degree of an error margin.";
        std::cout << "\nHence, points_form_nondegenerate_quadrilateral(POINT point_0, POINT point_1, POINT point_2, POINT point_3) is returning false.";
        return false;
    }
    return true;
}

/**
 * The default constructor of QUADRILATERAL calls POLYGON's constructor
 * and sets color to "orange" and quadrilateral points to
 * A(0,0), B(0,5), C(6,8), and D(3,0).
 */
QUADRILATERAL::QUADRILATERAL()
{
    A = POINT(0,0);
    B = POINT(0,5);
    C = POINT(6,8);
    D = POINT(3,0);
}

/**
 * The normal constructor of QUADRILATERAL attempts to set
 * the color and point values to the input values.
 * 
 * If those point values fail to represent a non-degenerate quadrilateral,
 * then set the point values to the coordinates of the default
 * quadrilateral points.
 */
QUADRILATERAL::QUADRILATERAL(std::string color, POINT A, POINT B, POINT C, POINT D)
{
    this -> color = color;
    if (!points_form_nondegenerate_quadrilateral(A, B, C, D))
    {
        this -> A = POINT(0,0);
        this -> B = POINT(0,5);
        this -> C = POINT(6,8);
        this -> D = POINT(3,0);
        return;
    }
    this -> A = POINT(A);
    this -> B = POINT(B);
    this -> C = POINT(C);
    this -> D = POINT(D);
}

/**
 * The copy constructor of QUADRILATERAL creates a clone of 
 * the input QUADRILATERAL instance.
 */
QUADRILATERAL::QUADRILATERAL(QUADRILATERAL & quadrilateral)
{
    A = quadrilateral.A;
    B = quadrilateral.B;
    C = quadrilateral.C;
    D = quadrilateral.D;
    color = quadrilateral.color;
}

/** 
 * The getter method of the QUADRILATERAL class named get_A() returns 
 * the value of the caller QUADRILATERAL object's A property.
 */
POINT QUADRILATERAL::get_A()
{
    return A;
}

/** 
 * The getter method of the QUADRILATERAL class named get_B() returns 
 * the value of the caller QUADRILATERAL object's B property.
 */
POINT QUADRILATERAL::get_B()
{
    return B;
}

/** 
 * The getter method of the QUADRILATERAL class named get_C() returns 
 * the value of the caller QUADRILATERAL object's C property.
 */
POINT QUADRILATERAL::get_C()
{
    return C;
}

/** 
 * The getter method of the QUADRILATERAL class named get_D() returns 
 * the value of the caller QUADRILATERAL object's D property.
 */
POINT QUADRILATERAL::get_D()
{
    return D;
}

/** 
 * The getter method of the QUADRILATERAL class named get_side_length_AB() 
 * returns the length of the shortest path between points A and B.
 */
double QUADRILATERAL::get_side_length_AB()
{
    return A.get_distance_from(B);
}

/** 
 * The getter method of the QUADRILATERAL class named get_side_length_BC() 
 * returns the length of the shortest path between points B and C.
 */
double QUADRILATERAL::get_side_length_BC()
{
    return B.get_distance_from(C);
}

/** 
 * The getter method of the QUADRILATERAL class named get_side_length_CD() 
 * returns the length of the shortest path between points C and D.
 */
double QUADRILATERAL::get_side_length_CD()
{
    return C.get_distance_from(D);
}

/** 
 * The getter method of the QUADRILATERAL class named get_side_length_DA() 
 * returns the length of the shortest path between points D and A.
 */
double QUADRILATERAL::get_side_length_DA()
{
    return D.get_distance_from(A);
}

/** 
 * The getter method of the QUADRILATERAL class named get_diagonal_length_AC() 
 * returns the length of the shortest path between points A and C.
 */
double QUADRILATERAL::get_diagonal_length_AC()
{
    return A.get_distance_from(C);
}

/** 
 * The getter method of the QUADRILATERAL class named get_diagonal_length_BD() 
 * returns the length of the shortest path between points B and D.
 */
double QUADRILATERAL::get_diagonal_length_BD()
{
    return B.get_distance_from(D);
}

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
double QUADRILATERAL::get_interior_angle_ABC()
{
    double a = 0.0, e = 0.0, d = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_e = 0.0, angle_opposite_of_d = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    e = get_diagonal_length_AC(); // e represents the length of the line segment whose endpoints are C and A.
    d = get_side_length_AB(); // d represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((e * e) + (d * d) - (a * a)) / (2 * e * d)) * (180 / PI);
    angle_opposite_of_e = acos(((a * a) + (d * d) - (e * e)) / (2 * a * d)) * (180 / PI);
    angle_opposite_of_d = acos(((a * a) + (e * e) - (d * d)) / (2 * a * e)) * (180 / PI);
    return angle_opposite_of_e;
}

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
double QUADRILATERAL::get_interior_angle_BCD()
{
    double a = 0.0, b = 0.0, f = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_f = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CD(); // b represents the length of the line segment whose endpoints are C and D.
    f = get_diagonal_length_BD(); // f represents the length of the line segment whose endpoints are D and B.
    angle_opposite_of_a = acos(((b * b) + (f * f) - (a * a)) / (2 * b * f)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (f * f) - (b * b)) / (2 * a * f)) * (180 / PI);
    angle_opposite_of_f = acos(((a * a) + (b * b) - (f * f)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_f;
}

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
double QUADRILATERAL::get_interior_angle_CDA()
{
    double b = 0.0, c = 0.0, e = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0, angle_opposite_of_e = 0.0;
    b = get_side_length_CD(); // b represents the length of the line segment whose endpoints are C and D.
    c = get_side_length_DA(); // c represents the length of the line segment whose endpoints are D and A.
    e = get_diagonal_length_AC(); // e represents the length of the line segment whose endpoints are A and C.
    angle_opposite_of_b = acos(((c * c) + (e * e) - (b * b)) / (2 * c * e)) * (180 / PI);
    angle_opposite_of_c = acos(((b * b) + (e * e) - (c * c)) / (2 * b * e)) * (180 / PI);
    angle_opposite_of_e = acos(((b * b) + (c * c) - (e * e)) / (2 * b * c)) * (180 / PI);
    return angle_opposite_of_e;
}

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
double QUADRILATERAL::get_interior_angle_DAB()
{
    double c = 0.0, d = 0.0, f = 0.0, angle_opposite_of_c = 0.0, angle_opposite_of_d = 0.0, angle_opposite_of_f = 0.0;
    c = get_side_length_DA(); // c represents the length of the line segment whose endpoints are D and A.
    d = get_side_length_AB(); // d represents the length of the line segment whose endpoints are A and B.
    f = get_diagonal_length_BD(); // f represents the length of the line segment whose endpoints are B and D.
    angle_opposite_of_c = acos(((d * d) + (f * f) - (c * c)) / (2 * d * f)) * (180 / PI);
    angle_opposite_of_d = acos(((c * c) + (f * f) - (d * d)) / (2 * c * f)) * (180 / PI);
    angle_opposite_of_f = acos(((c * c) + (d * d) - (f * f)) / (2 * c * d)) * (180 / PI);
    return angle_opposite_of_f;
}

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
double QUADRILATERAL::get_area()
{
    double s0 = 0.0, d = 0.0, a = 0.0, e = 0.0, s1 = 0.0, c = 0.0, b = 0.0, first_triangle_area = 0.0, second_triangle_area = 0.0;
    d = get_side_length_AB(); // d represents the length of the line segment whose endpoints are A and B.
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    e = get_diagonal_length_AC(); // e represents the length of the line segment whose endpoints are A and C.
    c = get_side_length_DA(); // c represents the length of the line segment whose endpoints are D and A.
    b = get_side_length_CD(); // b represents the length of the line segment whose endpoints are C and D.
    s0 = (d + a + e) / 2;
    s1 = (c + b + e) / 2;
    first_triangle_area = sqrt( s0 * (s0 - d) * (s0 - a) * (s0 - e) );
    second_triangle_area = sqrt( s1 * (s1 - c) * (s1 - b) * (s1 - e) );
    return first_triangle_area + second_triangle_area;
}

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
double QUADRILATERAL::get_perimeter()
{
    double d = 0.0, a = 0.0, b = 0.0, c = 0.0;
    d = get_side_length_AB(); // d represents the length of the line segment whose endpoints are A and B.
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CD(); // b represents the length of the line segment whose endpoints are C and D.
    c = get_side_length_DA(); // c represents the length of the line segment whose endpoints are D and A.
    return d + a + b + c;
}

/** 
 * This method overrides POLYGON's print method.
 * 
 * The descriptor method prints a description of the caller QUADRILATERAL to the output stream.
 * If no parameter is supplied, output is set to the command line.
 */
void QUADRILATERAL::print(std::ostream & output)
{
    output << "\n\n---------------------";
    output << "\nmemory_address := " << this << ". // address of first byte-sized memory cell in a QUADRILATERAL-object-sized block of such memory cells";
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
 * The friend function is not a member of the QUADRILATERAL class,
 * but it does have access to the members of QUADRILATERAL as though
 * it were a member of that class.
 */
std::ostream & operator << (std::ostream & output, QUADRILATERAL & quadrilateral)
{
    quadrilateral.print(output);
    return output;
}