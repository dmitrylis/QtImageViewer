#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <restdataprovider.h>

#include <userscontroller.h>
#include <albumscontroller.h>
#include <photoscontroller.h>
#include <commentscontroller.h>
#include <postscontroller.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    // Cretate objects
    Qiv::RestDataProvider restDataProvider; // we can have different data providers based on Qiv::DataProvider

    Qiv::UsersController usersController{&restDataProvider};
    Qiv::AlbumsController albumsController{&restDataProvider};
    Qiv::PhotosController photosController{&restDataProvider};
    Qiv::CommentsController commentsController{&restDataProvider};
    Qiv::PostsController postsController{&restDataProvider};

    // Create engine and register context properties
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_usersController", &usersController);
    engine.rootContext()->setContextProperty("_albumsController", &albumsController);
    engine.rootContext()->setContextProperty("_photosController", &photosController);
    engine.rootContext()->setContextProperty("_commentsController", &commentsController);
    engine.rootContext()->setContextProperty("_postsController", &postsController);

    const QUrl url(QStringLiteral("qrc:/res/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
