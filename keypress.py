from pynput import keyboard
f = open('saved_input.txt', 'w')
def on_press(key):
    if key == keyboard.Key.esc:
      
        return False  # stop listener
    try:
        k = key.char  # single-char keys
    except:
        k = key.name  # other keys
    
    if k in ['w','a','s','d']:
      if not k == ['']:
          f.write(k)
          f.close()
      return False

listener = keyboard.Listener(on_press=on_press)
listener.start()
listener.join()
