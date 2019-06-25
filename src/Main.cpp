#include "App.hpp"

int 
main(int argc, char * argv[]) 
{
    return g_application_run(G_APPLICATION(dusk_editor_app_new()), argc, argv);
}
