#ifndef SAVE
#define SAVE

/**
 * Saves the shapes created or loaded by writing it into a txt file
 * @param s The shapes that are going to be saved
 * @author Rémy Martinot
 */
void saveShapes(shapeGroup_t *s);

/**
 * Loads shapes from a txt file
 * @param s The shape group in which the shapes are going to be loaded
 * @author Rémy Martinot
 */
void loadShapes(shapeGroup_t *s);

#endif