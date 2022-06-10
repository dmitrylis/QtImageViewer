import QtQuick 2.15

import "../singletons"

import "../QivHelper.js" as QivHelper

Text {
    id: root

    enum TextType {
        Heading1 = 0,
        Heading2,
        Heading3,
        PrimaryText,
        SecondaryText
    }

    property int type: QivText.TextType.SecondaryText

    elide: Text.ElideRight
    wrapMode: Text.Wrap
    font {
        pixelSize: QivHelper.handleEnum(root.type, 30, 25, 20, 15, 15)
        bold: QivHelper.handleEnum(root.type, true, true, true, true, false)
    }
    color: QivStyle.colorTextDark
    maximumLineCount: 1
}
