#include <string>

using namespace std;

typedef enum { Red, Green, Yellow, Blue } tColor;

string colorToStr (tColor color);

char letter (tColor color);

bool isSafe (int space);

int playerStart (int player);