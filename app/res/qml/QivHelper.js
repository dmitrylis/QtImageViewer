function handleEnum(enumValue, ...args) {
    return (enumValue >= 0 && enumValue < args.length) ? args[enumValue] : undefined
}

// returns random value in range [0; 1) based on a seed
function random(seed) {
    let hash = 0

    if (seed.length === 0) {
        return hash
    }

    let chr
    for (let i = 0; i < seed.length; i++) {
        chr   = seed.charCodeAt(i)
        hash  = ((hash << 5) - hash) + chr
        hash |= 0 // Convert to 32bit integer
    }
    return Math.abs(hash) / 2147483647
}

// returns random value in range [0; ceiling) based on a seed
function randomCeiling(seed, ceiling) {
    return Math.floor(random(seed) * ceiling)
}

function opacify(color, opacity) {
    return Qt.rgba(color.r, color.g, color.b, opacity)
}
