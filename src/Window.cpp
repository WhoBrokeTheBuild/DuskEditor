#include "Window.hpp"
#include "App.hpp"

#include <cstdio>

struct _DuskEditorAppWindow
{
    GtkApplicationWindow parent;

    GtkWidget * gl_drawing_area;
};

struct _DuskEditorAppWindowClass
{
    GtkApplicationWindowClass parent;
};

G_DEFINE_TYPE(DuskEditorAppWindow, dusk_editor_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
gl_init(DuskEditorAppWindow * self)
{
    gtk_gl_area_make_current(GTK_GL_AREA(self->gl_drawing_area));

    if (gtk_gl_area_get_error(GTK_GL_AREA(self->gl_drawing_area))) {
        return;
    }

    if (!gladLoadGL()) {
        printf("Something went wrong!\n");
        exit(-1);
    }

    printf("OpenGL Version %s\n", glGetString(GL_VERSION));
    printf("GLSL Version %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("OpenGL Vendor %s\n", glGetString(GL_VENDOR));
    printf("OpenGL Renderer %s\n", glGetString(GL_RENDERER));

    glEnable(GL_MULTISAMPLE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

static void
gl_fini(DuskEditorAppWindow * self)
{

}

static gboolean
gl_draw(DuskEditorAppWindow * self)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    return true;
}

static void
dusk_editor_app_window_class_init(DuskEditorAppWindowClass * c)
{

    GtkWidgetClass * widget_class = GTK_WIDGET_CLASS(c);

    gtk_widget_class_set_template_from_resource(widget_class, "/DuskEditorAppWindow.ui");

    gtk_widget_class_bind_template_child(widget_class, DuskEditorAppWindow, gl_drawing_area);
    
    gtk_widget_class_bind_template_callback(widget_class, gl_init);
    gtk_widget_class_bind_template_callback(widget_class, gl_draw);
    gtk_widget_class_bind_template_callback(widget_class, gl_fini);
}

static void
dusk_editor_app_window_init(_DuskEditorAppWindow * self)
{
    gtk_widget_init_template(GTK_WIDGET(self));
}

GtkWidget *
dusk_editor_app_window_new(DuskEditorApp * app)
{
    return GTK_WIDGET(g_object_new(dusk_editor_app_window_get_type(), "application", app, NULL));
}
