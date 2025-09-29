# `_printf` — Custom printf Function (C)

> **Prototype**
>
> ```c
> int _printf(const char *format, ...);
> ```
>
> Returns the number of characters printed (excluding the terminating `'\0'`).  
> On error, returns `-1`.

---

## 📌 Overview
`_printf` is a simplified re-implementation of the C standard library `printf`.  
It prints formatted output to **stdout** using a format string composed of text and **conversion specifiers**.

---

## ✅ Features (What’s Implemented)
- Writes to **stdout** using `write(2)`.
- Handles a **format string** with ordinary characters and conversion **directives**.
- Returns the **count of printed characters**.
- Graceful failure if `format == NULL`.

### Supported Specifiers
> Update this list to match your code if needed.

| Specifier | Meaning                          | Example Input       | Example Output |
|-----------|----------------------------------|---------------------|----------------|
| `%c`      | Character                        | `'_printf("%c", 'A')` | `A`            |
| `%s`      | String                           | `"_printf("%s", "Hi")"` | `Hi`        |
| `%%`      | Literal percent                   | `"_printf("%%")"`     | `%`           |
| `%d`, `%i`| Signed decimal integer           | `"_printf("%d", -12)"` | `-12`       |

> (Optional extensions you **may** add if implemented):  
> `%u` (unsigned), `%o` (octal), `%x/%X` (hex), `%p` (pointer), `%b` (binary), flags (`+`, space, `#`, `0`, `-`), width, precision, length (`l`, `h`).

---

## 🧱 Constraints
- **Do not** use `printf`, `puts`, `fprintf`, etc.
- Allowed std headers typically: `stdarg.h`, `unistd.h`, `stdlib.h`, `limits.h`.
- Use **variadic arguments** via `va_list`, `va_start`, `va_arg`, `va_end`.
- Output is buffered internally then written with `write(2)` (or written directly).

---

## 🧪 Usage

### Build
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o test_printf
