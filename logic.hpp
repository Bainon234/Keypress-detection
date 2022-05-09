class interact {
  public:
  string return_pressed_key;
  string py_name = "keypress";
  string py_exe = "python ";
  string file_name = "saved_input";
  int player_location = 0;
  int counted = 0;
  bool stop_counter = true;
  fstream countering;

  void counter_interaction(){
    

      countering.open("counter.txt", ios::out);
      if (countering.is_open()) {
        countering << counted + 1;
        countering.close();
      }

      countering.open("counter.txt", ios:: in );

      if (countering.is_open()) {
        string line;
        while (getline(countering, line)) {
          counted = stoi(line);
        }
      }
      countering.close();
      file_name += std::to_string(counted);
      py_name += std::to_string(counted);
      file_name += ".txt";
      py_name += ".py";
      fstream pythf;
      pythf.open(py_name, ios::out);
      if (pythf.is_open()) {
        pythf << "from pynput import keyboard" << "\n";
        pythf << "counted = " << counted << "\n";
        pythf << "f = open(f'saved_input{counted}.txt', 'w')" << "\n";
        pythf << "def on_press(key):" << "\n";
        pythf << "    if key == keyboard.Key.esc:" << "\n";
        pythf << "        return False" << "\n";
        pythf << "    try:" << "\n";
        pythf << "        k = key.char" << "\n";
        pythf << "    except:" << "\n";
        pythf << "        k = key.name" << "\n";
        pythf << "    if not k == ['']:" << "\n";
        pythf << "        f.write(k)" << "\n";
        pythf << "        f.close()" << "\n";
        pythf << "        return False" << "\n";
        pythf << "listener = keyboard.Listener(on_press=on_press)" << "\n";
        pythf << "listener.start()" << "\n";
        pythf << "listener.join()" << "\n";
      }
      pythf.close();
      py_exe += py_name;
      stop_counter = false;
    
  }
  void returnkey() {
    cout << "\r";
    if (stop_counter == true) {
      countering.open("counter.txt", ios:: in );
      if (countering.is_open()) {
        string line;
        while (getline(countering, line)) {
          counted = stoi(line);
        }
        countering.close();
        counter_interaction();
        delete counter_interaction;
      }
      }
    counter_interaction();
    system(py_exe.c_str());
    fstream read_controls;
    read_controls.open(file_name, ios:: in );
    if (read_controls.is_open()) {
      string line;
      while (getline(read_controls, line)) {

        cout << "you pressed " << line << endl;

      }
      read_controls.close();
    }

  }
};