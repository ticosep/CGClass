#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <memory.h>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QWidget>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
private:
    GLuint vboVertices = 0;
    GLuint vboColors = 0;
    GLuint vboIndices = 0;

    GLuint vao = 0;

    std::unique_ptr<QVector4D[]>vertices = nullptr;
    std::unique_ptr<QVector4D[]>colors = nullptr;
    std::unique_ptr<unsigned int[]>indices = nullptr;

    GLuint shaderProgram;

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

    void createVBOs();
    void createShaders();

    void destroyVBOs();
    void destroyShaders();

protected :
    void initializeGL();
    void resizeGL(int width,int height);
    void paintGL();

signals:

public slots:
    void toggleBackgroundColor(bool);

};

#endif // OPENGLWIDGET_H
