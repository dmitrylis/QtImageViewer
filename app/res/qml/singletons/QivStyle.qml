pragma Singleton
import QtQuick 2.15

QtObject {
    // different sizes
    readonly property size sizeScreen: Qt.size(480, 480)
    readonly property size sizeTile: Qt.size(160, 160)

    // margins section
    readonly property int marginTiny: 5
    readonly property int marginSmall: 10
    readonly property int marginMedium: 15
    readonly property int marginLarge: 25
    readonly property int marginHuge: 35
    readonly property int marginGiant: 45
    readonly property int marginEnormous: 60
    readonly property int marginHumungous: 75

    // font sizes section
    readonly property int fontTiny: 8
    readonly property int fontSmall: 10
    readonly property int fontMedium: 12
    readonly property int fontLarge: 14
    readonly property int fontHuge: 16
    readonly property int fontGiant: 18
    readonly property int fontEnormous: 20

    // colors section
    readonly property color colorMainBg: "#FFFFFF"

    readonly property color colorInfoBg: "#d9d9d9"

    readonly property var colorButtonsSet: ["#e7463e", "#d4379e", "#b320ea"]

    readonly property color colorOverlayDark: "#80000000"
    readonly property color colorOverlayLight: "#80FFFFFF"

    readonly property color colorShadowDark: "#000000"
    readonly property color colorShadowLight: "#FFFFFF"

    readonly property color colorTextDark: "#000000"
    readonly property color colorTextLight: "#FFFFFF"

    readonly property var colorSet: ["#6ebcc6", "#e5695d", "#f3b150","#099145", "#0e74bc", "#e05073"]
}
