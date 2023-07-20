
/**
 * @brief Captura un solo caracter de stdin
 * 
 * @param chr direccion donde se guardara el caracter
 */
void charGet(char* chr){
    char space[3];
    strGet(space, 2);
    *chr = space[0];
}