#pragma once

#include <cstring>
#include <raylib.h>
#include <embedded_assets_data.hpp>

inline Image LoadEmbeddedImage(const char* name) {
    if (std::strcmp(name, "bullet.png") == 0) {
        return LoadImageFromMemory(".png", embedded_assets::BULLET_PNG, sizeof(embedded_assets::BULLET_PNG));
    }
    if (std::strcmp(name, "enemy.png") == 0) {
        return LoadImageFromMemory(".png", embedded_assets::ENEMY_PNG, sizeof(embedded_assets::ENEMY_PNG));
    }
    if (std::strcmp(name, "gameoverscreen.png") == 0) {
        return LoadImageFromMemory(".png", embedded_assets::GAMEOVERSCREEN_PNG, sizeof(embedded_assets::GAMEOVERSCREEN_PNG));
    }
    if (std::strcmp(name, "heart.png") == 0) {
        return LoadImageFromMemory(".png", embedded_assets::HEART_PNG, sizeof(embedded_assets::HEART_PNG));
    }
    if (std::strcmp(name, "player.png") == 0) {
        return LoadImageFromMemory(".png", embedded_assets::PLAYER_PNG, sizeof(embedded_assets::PLAYER_PNG));
    }
    if (std::strcmp(name, "titlescreen.png") == 0) {
        return LoadImageFromMemory(".png", embedded_assets::TITLESCREEN_PNG, sizeof(embedded_assets::TITLESCREEN_PNG));
    }
    return Image{};
}