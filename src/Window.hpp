#ifndef DUSK_EDITOR_WINDOW_HPP
#define DUSK_EDITOR_WINDOW_HPP

#include <gtk/gtk.h>
#include <glad/glad.h>
#include "App.hpp"

G_BEGIN_DECLS

#define DUSK_EDITOR_TYPE_APP_WINDOW (dusk_editor_window_get_type())

G_DECLARE_FINAL_TYPE(DuskEditorAppWindow, dusk_editor_app_window, DUSK_EDITOR, APP_WINDOW, GtkApplicationWindow)

GtkWidget * dusk_editor_app_window_new(DuskEditorApp * app);

G_END_DECLS

#endif // DUSK_EDITOR_WINDOW_HPP