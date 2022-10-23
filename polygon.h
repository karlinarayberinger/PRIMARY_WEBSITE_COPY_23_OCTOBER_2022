/**
 * @file: polygon.h
 * @type: C++ (header file)
 * @date: 01_AUGUST_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * If polygon.h has not already been linked to a source file (.cpp), 
 * then link this header file to the source file(s) which include this header file.
 */
#ifndef POLYGON_H 
#define POLYGON_H

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the POINT class.
 */
#include "point.h" 

/**
 * Include the C++ library for instantiating strings.
 */
#include <string>

/**
 * POLYGON is abstract class whose members are the essential components of polygons 
 * such as TRILATERAL, RIGHT_TRILATERAL, QUADRILATERAL, TRAPEZOID, RECTANGLE, and SQUARE.
 * 
 * An abstract class has at least one virtual function.
 * 
 * The POLYGON class includes the POINT class via composition and
 * not via inheritance.
 * 
 * Class members which are set to the protected access specifier
 * are accessible to the encompassing base class and to classes which
 * are derived from that base class.
 * 
 * Class members which are set to the private access specifier
 * are only accessible to their ecompassing base class.
 * 
 * Class members which are set to the public access specifier
 * are accessible to any scope within the program where
 * the base class and its derived classes are implemented.
 */
class POLYGON
{
protected:
    
    /**
     * category is a description of the POLYGON instance.
     * category is set to a const (i.e. const (i.e. immutable)) value.
     */
    const std::string category = "POLYGON";
    
    /**
     * color is an arbitrary value.
     * color is used to demonstrate how abstract constructors work.
     */
    std::string color;
    
public:
    
    /**
     * The default POLYGON constructor sets the color value to some arbitrary value.
     * 
     * Note that the POLYGON cannot be instantiated as an object which takes
     * up some allotment of physical memory because the POLYGON class is
     * abstract. 
     * 
     * This constructor is implemented only by classes which are
     * descendents of the POLYGON class.
     * 
     * It is possible, however, to make POLYGON-type pointers which
     * store the memory of objects which are instantiated from classes
     * which are derived from the POLYGON class. (See the example below).
     * 
     ******************************************************************************
     * 
     * Source Code Example of how to indirectly call the print method of POLYGON...
     * 
     ******************************************************************************
     * 
     * // Does not work because POLYGON is an abstract class.
     * // POLYGON polygon; 
     * 
     * // Can point to instances of non-abstract derived classes of 
     * // POLYGON such as QUADRILATERAL.
     * POLYGON * pointer_to_polygon; 
     * 
     * // Assign memory to a dynamic QUADRILATERAL instance 
     * // (i.e. and dynamic implies that the variable was assigned memory during 
     * // program runtime instead of during program compile time).
     * pointer_to_polygon = new QUADRILATERAL; 
     * 
     * // Indirectly call the POLYGON print method.
     * pointer_to_polygon -> print(output); 
     * 
     ******************************************************************************
     * 
     * Source Code Example output...
     * 
     ******************************************************************************
     * 
     * ---------------------
     * memory_address := 0x56046761b4b0.
     * category := POLYGON.
     * color := orange.
     * ---------------------
     * 
     ******************************************************************************
     */
    POLYGON();
    
    /**
     * The virtual methods get_area() and get_perimeter() must be defined by 
     * classes which are derived from POLYGON.
     */
    virtual double get_area() = 0;
    virtual double get_perimeter() = 0;

    /**
     * The descriptor method prints a description of the POLYGON to the output stream.
     * If no parameter is supplied, output is set to the command line.
     */
    void print(std::ostream & output = std::cout);

    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the POLYGON class,
     * but it does have access to all ot the members of POLYGON as 
     * though it were a member function of the POLYGON class.
     */
    friend std::ostream & operator << (std::ostream & output, POLYGON & polygon);
};

/**
 * End of header file
 */
#endif