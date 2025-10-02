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

---

## Build

\`\`\`sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o test_printf
\`\`\`

## Supported specifiers

- `%c`, `%s`, `%%`, `%d`, `%i`

## Behavior & Edge cases
- Returns `-1` and prints nothing if `format == NULL`.
- Returns `-1` and prints nothing if the format string ends with a lone `%`.

## Notes
- Uses `stdarg.h` (va_list/va_start/va_arg/va_end)
- Writes via `write(2)` only, no globals, ≤ 5 functions per file

## Man page
Run `man -l man/man_3_printf` to read the local manual page.

---

## Build

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o test_printf


---

## Description
Minimal `_printf` supporting %c, %s, %%, %d, %i with write(2).

## Requirements
Ubuntu 20.04, gcc, no globals, ≤ 5 functions per file.

## Build
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o test_printf
```

## Example
```c
_printf("Hello %s %d%%\\n", "world", 100);
```

## Man page
man -l man/man_3_printf

## Requirements
- Ubuntu 20.04
- gcc with: -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

## Examples
\`\`\`c
/* prints: Hello world 100% */
int n = _printf("Hello %s %d%%\n", "world", 100);
\`\`\`

## Testing
- Compare with libc printf using -Wno-format
- Keep local tests under tests/ (gitignored)

---

## Team / Collaboration

This project is a two–person effort:

- **Fahad Abdulaziz Alghamdi** — base specifiers `%c`, `%s`, `%%`, repository bootstrap.
- **Yasir Musaad Alshabanah** — integer specifiers `%d`, `%i`, edge-cases & QA, `man_3_printf`.

**Workflow:** each feature lands on a dedicated branch → Pull Request → partner review → merge to `main`.  
**Environment:** Ubuntu 20.04, `gcc -Wall -Werror -Wextra -pedantic -std=gnu89` (and `-Wno-format` for local comparisons).


---

## Description
Minimal `_printf` supporting %c, %s, %%, %d, %i with write(2).

## Requirements
Ubuntu 20.04, gcc, no globals, ≤ 5 functions per file.

## Build
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o test_printf
```

## Example
```c
_printf("Hello %s %d%%\\n", "world", 100);
```

## Man page
man -l man/man_3_printf
