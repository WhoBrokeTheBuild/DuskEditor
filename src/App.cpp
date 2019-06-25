#include "App.hpp"
#include "Window.hpp"

struct _DuskEditorApp
{
    GtkApplication parent;

    GtkWidget * window;
};

struct _DuskEditorClass
{
    GtkApplicationClass parent;
};

G_DEFINE_TYPE(DuskEditorApp, dusk_editor_app, GTK_TYPE_APPLICATION);

static void
exit_activated(
    GSimpleAction * action,
    GVariant * parameter,
    gpointer app)
{
    g_application_quit(G_APPLICATION(app));
}

static GActionEntry app_entries[] = 
{
    { "exit", exit_activated, NULL, NULL, NULL },
};

static void
dusk_editor_app_startup(GApplication * app)
{
    GtkBuilder * builder;

    G_APPLICATION_CLASS(dusk_editor_app_parent_class)->startup(app);

    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entries, G_N_ELEMENTS(app_entries), app);
}

static void
dusk_editor_app_activate(GApplication * app) 
{
    DuskEditorApp * self = DUSK_EDITOR_APP(app);

    if (!self->window) {
        self->window = dusk_editor_app_window_new(self);
    }

    gtk_window_present(GTK_WINDOW(self->window));
}

static void
dusk_editor_app_class_init(DuskEditorAppClass * c) {
    GApplicationClass * app_class = G_APPLICATION_CLASS(c);

    app_class->startup = dusk_editor_app_startup;
    app_class->activate = dusk_editor_app_activate;
}

static void
dusk_editor_app_init(DuskEditorApp * self) 
{

}

GtkApplication *
dusk_editor_app_new(void)
{
    return GTK_APPLICATION(g_object_new(dusk_editor_app_get_type(), "application-id", "com.stephenlw.DuskEditor", NULL));
}