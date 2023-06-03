const mongoose = require('mongoose');
const { Schema } = mongoose;

const PlayerSchema = new Schema({
    username: {
        type: String,
        required: true,
    },
    level: {
        type: String,
        required: true,
    },
    spriteSheet: {
        type: String,
        required: true,
    },
    playerX: {
        type: String,
        required: true,
    },
    playerY: {
        type: String,
        required: true,
    },
    playerDirection: {
        type: String,
        required: true,
    },
    cameraX: {
        type: String,
        required: true,
    },
    cameraY: {
        type: String,
        required: true,
    },
    map: {
        type: String,
        required: true,
    },

});

module.exports = mongoose.model('Player', PlayerSchema);