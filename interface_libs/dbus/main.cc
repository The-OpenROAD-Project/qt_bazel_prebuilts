#include <dbus/dbus.h>

int main(int argc, char** argv) {
       char* x = dbus_get_local_machine_id();
       return (long)(x);
}