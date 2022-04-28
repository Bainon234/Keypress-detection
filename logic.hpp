
class game {
  public:
  string return_pressed_key;
  int player_location = 0;

   void returnkey() {
      cout << "\r";

      fstream read_controls;
      read_controls.open("saved_input.txt", ios:: in );
      if (read_controls.is_open()) {
         string line;
         while (getline(read_controls, line)) {
            cout << "you pressed " << line << endl;
         }
         read_controls.close();
      }
     
   }
   void player_moves() {
      string y = " ";
      for (int i = 0; i < 0 + player_location; i++) {
         y += y;
      }
      if (return_pressed_key == "d") {
         cout << y << 1;

      }
   }
};