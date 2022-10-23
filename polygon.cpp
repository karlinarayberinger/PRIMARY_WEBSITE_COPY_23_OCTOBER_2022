/**
 * @file: polygon.cpp
 * @type: C++ (source file)
 * @date: 01_AUGUST_2022
 * @author: Karlina Ray Beringer
 * @license: PUBLIC_DOMAIN
 */

/**
 * Include the C++ header file which contains preprocessing directives, 
 * variable declarations, and function prototypes for the POLYGON class.
 */
#include "polygon.h" 

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
POLYGON::POLYGON()
{
    color = "orange";
}

/**
 * The virtual methods get_area() and get_perimeter() must be defined by 
 * classes which are derived from POLYGON.
 */
double POLYGON::get_area() { return 0.0; }
double POLYGON::get_perimeter() { return 0.0; }

/**
 * The descriptor method prints a description of the POLYGON to the output stream.
 * If no parameter is supplied, output is set to the command line.
 */
void POLYGON::print(std::ostream & output)
{
    output << "\n\n---------------------";
    output << "\nmemory_address := " << this << ".";
    output << "\ncategory := " << category << ".";
    output << "\ncolor := " << color << ".";
    output << "\n---------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the POLYGON class,
 * but it does have access to all ot the members of POLYGON as 
 * though it were a member function of the POLYGON class.
 */
std::ostream & operator << (std::ostream & output, POLYGON & polygon)
{
    polygon.print(output);
    return output;
}
