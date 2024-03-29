#include <parchis.hpp>

using namespace std;

void display(const tGame& game) {
   int space, marker;
   tColor plyr;

   cout << "\x1b[2J\x1b[H"; // Se situa en la esquina superior izquierda
   setColor(Gray);
   cout << endl;

   // Filas con la numeraci�n de las spaces...
   for (int i = 0; i < NUM_SPACES; i++)
      cout << i / 10;
   cout << endl;
   for (int i = 0; i < NUM_SPACES; i++)
      cout << i % 10;
   cout << endl;

   // Borde superior...
   for (int i = 0; i < NUM_SPACES; i++)
      cout << '>';
   cout << endl;

   // Primera fila de posiciones de markers...
   for (int i = 0; i < NUM_SPACES; i++) {
      setColor(game.spaces[i].lane2);
      if (game.spaces[i].lane2 != None)
         cout << firstAt(game.players[game.spaces[i].lane2].markers, i) + 1;
      else
         cout << ' ';
      setColor(Gray);
   }
   cout << endl;

   // "Mediana"   
   for (int i = 0; i < NUM_SPACES; i++)
      if (isSafe(i))
         cout << 'o';
      else
         cout << '-';
   cout << endl;


   // Segunda fila de posiciones de markers...
   for (int i = 0; i < NUM_SPACES; i++) {
      setColor(game.spaces[i].lane1);
      if (game.spaces[i].lane1 != None)
         cout << secondAt(game.players[game.spaces[i].lane1].markers, i) + 1;
      else
         cout << ' ';
      setColor(Gray);
   }
   cout << endl;

   plyr = Yellow;
   // Borde inferior...
   for (int i = 0; i < NUM_SPACES; i++)
      if (i == zanataSpace(plyr)) {
         setColor(plyr);
         cout << "V";
         setColor(Gray);
      }
      else if (i == startSpace(plyr)) {
         setColor(plyr);
         cout << "^";
         setColor(Gray);
         plyr = tColor(int(plyr) + 1);
      }
      else
         cout << '>';
   cout << endl;

   // Metas y casas...
   for (int i = 0; i < NUM_MARKERS; i++) {
      space = 0;
      plyr = Yellow;
      setColor(plyr);
      while (space < NUM_SPACES) {
         if (space == zanataSpace(plyr)) {
            marker = firstAt(game.players[plyr].markers, 101 + i);
            if (marker != -1) {
               cout << marker + 1;
               if (howMany(game.players[plyr].markers, 101 + i) > 1) {
                  marker = secondAt(game.players[plyr].markers, 101 + i);
                  if (marker != -1) {
                     cout << marker + 1;
                  }
                  else
                     cout << "V";
               }
               else
                  cout << "V";
            }
            else
               cout << "VV";
            space++;
         }
         else if (space == startSpace(plyr)) {
            if (game.players[plyr].markers[i] == -1) // En casa
               cout << i + 1;
            else
               cout << "^";
            plyr = tColor(int(plyr) + 1);
            setColor(plyr);
         }
         else
            cout << ' ';
         space++;
      }
      cout << endl;
   }

   // Resto de metas...
   for (int i = 105; i <= 107; i++) {
      space = 0;
      plyr = Yellow;
      setColor(plyr);
      while (space < NUM_SPACES) {
         if (space == zanataSpace(plyr)) {
            marker = firstAt(game.players[plyr].markers, i);
            if (marker != -1) {
               cout << marker + 1;
               if (howMany(game.players[plyr].markers, i) > 1) {
                  marker = secondAt(game.players[plyr].markers, i);
                  if (marker != -1) {
                     cout << marker + 1;
                  }
                  else
                     cout << "V";
               }
               else
                  cout << "V";
            }
            else
               cout << "VV";
            space++;
            plyr = tColor(int(plyr) + 1);
            setColor(plyr);
         }
         else
            cout << ' ';
         space++;
      }
      cout << endl;
   }

   space = 0;
   plyr = Yellow;
   setColor(plyr);
   while (space < NUM_SPACES) {
      cout << ((game.players[plyr].markers[0] == 108) ? '1' : '.');
      cout << ((game.players[plyr].markers[1] == 108) ? '2' : '.');
      plyr = tColor(int(plyr) + 1);
      setColor(plyr);
      cout << "               ";
      space += 17;
   }
   cout << endl;
   space = 0;
   plyr = Yellow;
   setColor(plyr);
   while (space < NUM_SPACES) {
      cout << ((game.players[plyr].markers[2] == 108) ? '3' : '.');
      cout << ((game.players[plyr].markers[3] == 108) ? '4' : '.');
      plyr = tColor(int(plyr) + 1);
      setColor(plyr);
      cout << "               ";
      space += 17;
   }
   cout << endl << endl;
   setColor(Gray);
}
