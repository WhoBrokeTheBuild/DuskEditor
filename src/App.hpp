#ifndef DUSK_EDITOR_APP_HPP
#define DUSK_EDITOR_APP_HPP

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define DUSK_EDITOR_TYPE_APP (dusk_editor_app_get_type())

G_DECLARE_FINAL_TYPE(DuskEditorApp, dusk_editor_app, DUSK_EDITOR, APP, GtkApplication)

GtkApplication * dusk_editor_app_new(void);

G_END_DECLS

#endif // DUSK_EDITOR_APP_HPP