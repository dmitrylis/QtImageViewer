import QtQuick 2.15
import QtGraphicalEffects 1.12

import "../QivHelper.js" as QivHelper

import "../singletons"

DropShadow {
    id: root

    property real alpha: 0.5
    property color shadowColor: QivStyle.colorShadowDark

    horizontalOffset: 0
    verticalOffset: 3
    radius: 15
    samples: 2 * radius + 1
    cached: true
    color: QivHelper.opacify(root.shadowColor, root.alpha)
}
