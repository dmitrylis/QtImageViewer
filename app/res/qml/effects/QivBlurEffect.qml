import QtQuick 2.15
import QtGraphicalEffects 1.12

GaussianBlur {
    radius: 70
    samples: radius * 2
    cached: true
}
