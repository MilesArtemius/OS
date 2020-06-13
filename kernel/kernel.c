#include "../drivers/screen.h"
#include "interruption_tables.h"
#include "timer.h"
#include "../drivers/keyboard.h"

/**
 * Make kernel constants:
 *
 *
 *
 * Divide boot loader into: loader, functions, GDT.
 *
 * First man 2 implement: https://web.archive.org/web/20160324232118/http://jamesmolloy.co.uk/tutorial_html/
 * Second man 2 implement: https://github.com/cfenollosa/os-tutorial
 *
 * Documentation! For each stage!
 * 0. Paging + heap + memory functions (dummy RAM positioning) -> Arrays, stack, line -> string -> logger.
 * 1. Kernel constants (root CS and root DS (passed from loader), booting device, kernel size, max RAM)
 *                          -> define RAM positions everywhere (loader, interruptions).
 * 2. Memory map -> positioning of kernel / stack + kernel loading size (written in boot sector, defined after compilation).
 * 3. Shell + audio drivers.
 * 4. File system + initrd.
 * 6. Multitasking.
 * 7. User mode.
 * 8. Video mode.
 * 9. Sample apps.
 * 10. Und so weiter...
 */

int kek() {
    char* video_memory = (char*) 0xb8000;
    video_memory[0] = 'A';
    return 0;
}

void _start() {
    clear_screen();
    print_color("Kernel started!\n", YELLOW, BLACK);
    init_interruptions();
    init_keyboard();
    init_timer(100);
}
