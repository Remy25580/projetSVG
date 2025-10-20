#ifndef SVG
#define SVG

/**
 * Determines what is the maximum x in your shapes
 * @param s The list of shapes in which the x maximum is going to be calculated
 * @return The maximum
 * @author Rémy Martinot
 */
float xMax(shapeGroup_t *s);

/**
 * Determines what is the maximum y in your shapes
 * @param s The list of shapes in which the y maximum is going to be calculated
 * @return The maximum
 * @author Rémy Martinot
 */
float yMax(shapeGroup_t *s);

/**
 * Writes the svg shapes into an SVG file
 * @param s The list of shapes that are going to be written
 * @param x The dimension x of the viewbox
 * @param y The dimension y of the viewbox
 * @author Rémy Martinot
 */
void svgShapes(shapeGroup_t *s, float x, float y);
#endif