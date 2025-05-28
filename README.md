# 🖥️ Termcode

**Termcode** is a minimal terminal-based text editor written in C, designed to work directly with the terminal environment using ANSI escape codes. It demonstrates low-level manipulation of terminal buffers, keyboard input processing, and text rendering—ideal for educational purposes or as a starting point for building TUIs (Terminal User Interfaces).

---

## 📁 Project Structure

```
termcode/
├── Makefile                  # Build instructions
├── main.c                    # Entry point of the application
├── inc/
│   ├── get_next_line.h       # Header for custom line reader
│   └── termcode.h            # Main editor data structures and function declarations
├── src/
│   ├── cursor_movements.c    # Handles cursor navigation logic
│   ├── erase.c               # Functions to handle deletion of characters and lines
│   ├── free_all.c            # Memory management and cleanup
│   ├── get_next_line.c       # Custom implementation of getline
│   ├── get_next_line_utils.c# Utilities for getline implementation
│   ├── init_text.c           # Initializes editor's text buffer
│   ├── keypress_process.c    # Processes key inputs (navigation, editing)
│   ├── new_line.c            # Handles line breaking and insertion
│   ├── putch.c               # Outputs characters to the terminal
│   ├── save.c                # Saving contents to a file
│   ├── terminal_env.c        # Configures terminal I/O modes
│   ├── text_utils.c          # Text editing helpers (e.g., insert char)
│   └── utils.c               # General utilities
```

---

## ⚙️ Build & Run

### Requirements
- GCC or Clang
- A Unix-like OS (Linux/macOS)
- Terminal with ANSI support

### Build

```bash
make
```

### Run

```bash
./termcode
```

---

## 🧠 Features

- Line-by-line input using a custom `get_next_line` function
- Full raw terminal mode (non-canonical input handling)
- Cursor movement (arrows)
- Text insertion and deletion
- Save to file functionality
- Minimal memory-safe buffer management

---

## 📌 Key Bindings

| Key         | Action               |
|-------------|----------------------|
| ↑ ↓ ← →     | Navigate text        |
| `Enter`     | Insert new line      |
| `Backspace` | Delete character     |
| `Ctrl+S`    | Save to file         |
| `Ctrl+C`    | Exit gracefully      |

---

## 🧼 Clean

```bash
make fclean
```

---

## 📚 Educational Value

This project is useful for:

- Learning about terminal control in C (termios, escape sequences)
- Understanding the foundation of text editors
- Practicing memory-safe dynamic buffer manipulation
- Implementing basic software architecture in C

---

## 👨‍💻 Author

- **Yassine Ouakidi**  
  GitHub: [@YassineOuakidi](https://github.com/YassineOuakidi)

---

## 📄 License

This project is open-source under the [MIT License](LICENSE).
