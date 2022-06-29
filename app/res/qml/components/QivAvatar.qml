import QtQuick 2.15

import "../singletons"
import "../effects"

import "../QivHelper.js" as QivHelper

Rectangle {
    id: root

    property string name

    QtObject {
        id: internal

        function color(seed) {
            const colors = QivStyle.colorSet
            return colors[QivHelper.randomCeiling(seed, colors.length)]
        }

        function acronym(name) {
            const words = name.split(" ")
            let letters = ""

            for (let i = 0; i < 2 && i < words.length; ++i) {
                letters += words[i][0]
            }
            return letters
        }
    }

    width: 100
    height: width
    color: internal.color(root.name)
    radius: height * 0.5

    layer {
        enabled: true
        effect: QivShadowEffect { alpha: 0.3 }
    }

    QivText {
        anchors.centerIn: parent
        text: internal.acronym(root.name)
        type: QivText.TextType.Heading1
    }
}
