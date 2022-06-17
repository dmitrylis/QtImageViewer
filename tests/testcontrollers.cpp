#include <QtTest>
#include <QCoreApplication>

#include <QSignalSpy>

#include "mockdataprovider.h"

#include <userscontroller.h>
#include <albumscontroller.h>
#include <photoscontroller.h>
#include <commentscontroller.h>
#include <postscontroller.h>

using namespace Qiv;

class TestControllers : public QObject
{
    Q_OBJECT

public:
    TestControllers();
    ~TestControllers();

private slots:
    void test_users();
    void test_albums();
    void test_photos();
    void test_comments();
    void test_posts();

private:
    MockDataProvider m_mockDataProvider;
};

TestControllers::TestControllers()
{
}

TestControllers::~TestControllers()
{
}

void TestControllers::test_users()
{
    UsersController userController{&m_mockDataProvider};

    // verifying initial parameters
    QCOMPARE(userController.property("selectedUserId").toInt(), 0);
    QVERIFY(userController.property("selectedUserData").toJsonObject().empty());

    QJsonArray usersModel = userController.property("usersModel").toJsonArray();
    QCOMPARE(usersModel.count(), 0);

    // requesting data
    QSignalSpy requestUsersSpy(&userController, &UsersController::usersModelChanged);
    userController.requestUsers();
    QCOMPARE(requestUsersSpy.count(), 1);

    // verifying received data
    usersModel = userController.property("usersModel").toJsonArray();
    QCOMPARE(usersModel.count(), 10);

    // trying to select some user and verify data
    userController.selectUser(1);
    QCOMPARE(userController.property("selectedUserId").toInt(), 1);
    QVERIFY(!userController.property("selectedUserData").toJsonObject().empty());

    // forgetting the user and verify data
    userController.forgetUser();
    QCOMPARE(userController.property("selectedUserId").toInt(), 0);
    QVERIFY(userController.property("selectedUserData").toJsonObject().empty());
}

void TestControllers::test_albums()
{
    AlbumsController albumsController{&m_mockDataProvider};

    // verifying initial parameters
    QCOMPARE(albumsController.property("selectedAlbumId").toInt(), 0);

    QJsonArray albumsModel = albumsController.property("albumsModel").toJsonArray();
    QCOMPARE(albumsModel.count(), 0);

    QJsonArray userAlbumsModel = albumsController.property("userAlbumsModel").toJsonArray();
    QCOMPARE(userAlbumsModel.count(), 0);

    // requesting data
    QSignalSpy requestAlbumsSpy(&albumsController, &AlbumsController::albumsModelChanged);
    albumsController.requestAlbums();
    QCOMPARE(requestAlbumsSpy.count(), 1);

    QSignalSpy requestUserAlbumsSpy(&albumsController, &AlbumsController::userAlbumsModelChanged);
    albumsController.requestUserAlbums(1);
    QCOMPARE(requestUserAlbumsSpy.count(), 1);

    // verifying received data
    albumsModel = albumsController.property("albumsModel").toJsonArray();
    QCOMPARE(albumsModel.count(), 100);

    userAlbumsModel = albumsController.property("userAlbumsModel").toJsonArray();
    QCOMPARE(userAlbumsModel.count(), 10);

    // trying to select some album and verify data
    albumsController.selectAlbum(1);
    QCOMPARE(albumsController.property("selectedAlbumId").toInt(), 1);

    // forgetting the album and verify data
    albumsController.forgetAlbum();
    QCOMPARE(albumsController.property("selectedAlbumId").toInt(), 0);

    // resetting and verifying data
    albumsController.resetAlbums();
    albumsController.resetUserAlbums();

    albumsModel = albumsController.property("albumsModel").toJsonArray();
    QCOMPARE(albumsModel.count(), 0);

    userAlbumsModel = albumsController.property("userAlbumsModel").toJsonArray();
    QCOMPARE(userAlbumsModel.count(), 0);
}

void TestControllers::test_photos()
{
    PhotosController photosController{&m_mockDataProvider};

    // verifying initial parameters
    QCOMPARE(photosController.property("photosCount").toInt(), 0);

    QJsonArray albumPhotosModel = photosController.property("albumPhotosModel").toJsonArray();
    QCOMPARE(albumPhotosModel.count(), 0);

    // requesting photos
    QSignalSpy requestPhotosSpy(&photosController, &PhotosController::photosCountChanged);
    photosController.requestPhotos();
    QCOMPARE(requestPhotosSpy.count(), 1);

    QSignalSpy requestAlbumPhotosSpy(&photosController, &PhotosController::albumPhotosModelChanged);
    photosController.requestAlbumPhotos(1);
    QCOMPARE(requestAlbumPhotosSpy.count(), 1);

    // verifying received data
    QCOMPARE(photosController.property("photosCount").toInt(), 5000);

    albumPhotosModel = photosController.property("albumPhotosModel").toJsonArray();
    QCOMPARE(albumPhotosModel.count(), 50);

    // resetting and verifying data
    photosController.resetPhotos();
    photosController.resetAlbumPhotos();

    QCOMPARE(photosController.property("photosCount").toInt(), 0);

    albumPhotosModel = photosController.property("albumPhotosModel").toJsonArray();
    QCOMPARE(albumPhotosModel.count(), 0);
}

void TestControllers::test_comments()
{
    CommentsController commentsController{&m_mockDataProvider};

    // verifying initial parameters
    QCOMPARE(commentsController.property("commentsCount").toInt(), 0);

    // requesting comments
    QSignalSpy requestCommentsSpy(&commentsController, &CommentsController::commentsCountChanged);
    commentsController.requestComments();
    QCOMPARE(requestCommentsSpy.count(), 1);

    // verifying received data
    QCOMPARE(commentsController.property("commentsCount").toInt(), 500);

    // resetting and verifying data
    commentsController.resetComments();
    QCOMPARE(commentsController.property("commentsCount").toInt(), 0);
}

void TestControllers::test_posts()
{
    PostsController postsController{&m_mockDataProvider};

    // verifying initial parameters
    QCOMPARE(postsController.property("postsCount").toInt(), 0);

    // requesting posts
    QSignalSpy requestPostsSpy(&postsController, &PostsController::postsCountChanged);
    postsController.requestPosts();
    QCOMPARE(requestPostsSpy.count(), 1);

    // verifying received data
    QCOMPARE(postsController.property("postsCount").toInt(), 100);

    // resetting and verifying data
    postsController.resetPosts();
    QCOMPARE(postsController.property("postsCount").toInt(), 0);
}

QTEST_MAIN(TestControllers)

#include "testcontrollers.moc"
