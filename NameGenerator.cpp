#include "NameGenerator.h"
#include <stdexcept>

namespace edu {

NameGenerator::NameGenerator() {

    // ---------------------------
    // 简体中文（潮流 + 网感）
    // ---------------------------
    teacherPools[Language::SimplifiedChinese] = {
        "慕辰", "景澄", "时宴", "云深", "白烁",
        "行之", "祁峋", "顾野", "晏行", "星澈"
    };

    studentPools[Language::SimplifiedChinese] = {
        "沐阳", "星然", "初晴", "若曦", "霖泽",
        "以安", "澈蓝", "清欢", "时柠", "景予"
    };

    // ---------------------------
    // 繁體中文（文青 + 詩意）
    // ---------------------------
    teacherPools[Language::TraditionalChinese] = {
        "子衿", "暮寒", "清和", "澄心", "安澈",
        "懷瑾", "雲舒", "景行", "安歌", "知涯"
    };

    studentPools[Language::TraditionalChinese] = {
        "明澈", "星朗", "瑾瑜", "熙和", "清月",
        "南湘", "沐芷", "辰溪", "子願", "明栀"
    };

    // ---------------------------
    // English（美式 · 多元 + 力量感）
    // ---------------------------
    teacherPools[Language::English] = {
        "Hunter", "Logan", "Maverick", "Jackson", "Carter",
        "Victoria", "Madison", "Brooklyn", "Autumn", "Faith"
    };

    studentPools[Language::English] = {
        "Aiden", "Chase", "Riley", "Harper", "Madeline",
        "Ethan", "Blake", "Zoe", "Levi", "Aubrey"
    };

    // ---------------------------
    // Japanese（日本語 · 自然意象）
    // ---------------------------
    teacherPools[Language::Japanese] = {
        "悠真", "蓮", "颯太", "葵", "結衣",
        "陽斗", "大和", "涼真", "悠斗", "真琴"
    };

    studentPools[Language::Japanese] = {
        "陽菜", "紗良", "美咲", "海斗", "凛",
        "葵花", "結月", "優奈", "玲奈", "春樹"
    };

    // ---------------------------
    // Korean（한국어 · 清冷 + 偶像感）
    // ---------------------------
    teacherPools[Language::Korean] = {
        "준호", "지훈", "민석", "수진", "서현",
        "하준", "도현", "윤서", "지수", "민재"
    };

    studentPools[Language::Korean] = {
        "지민", "서연", "민서", "하늘", "유진",
        "다은", "지아", "윤호", "민지", "수아"
    };

    // ---------------------------
    // Spanish（Español · 阳光 + 热情）
    // ---------------------------
    teacherPools[Language::Spanish] = {
        "Álvaro", "Mateo", "Carmen", "Lucía", "Javier",
        "Sofía", "Diego", "Marcos", "Elena", "Pablo"
    };

    studentPools[Language::Spanish] = {
        "María", "Daniela", "Diego", "Pablo", "Ángela",
        "Sofía", "Antonio", "Liliana", "Carlos", "Isabel"
    };

    // ---------------------------
    // French（Français · 革命 + 浪漫）
    // ---------------------------
    teacherPools[Language::French] = {
        "Étienne", "Laurent", "Mathieu", "Camille", "Élodie",
        "Adrien", "Lucien", "Amélie", "Aurélien", "Renée"
    };

    studentPools[Language::French] = {
        "Léa", "Chloé", "Hugo", "Lilou", "Noé",
        "Émile", "Nina", "Clara", "Théo", "Énzo"
    };
}


// -----------------------------------------------------
// 获取老师名字
// -----------------------------------------------------
std::string NameGenerator::getTeacherName(Language lang, int index) const {
    auto it = teacherPools.find(lang);
    if (it == teacherPools.end() || it->second.empty()) {
        return "UnknownTeacher";
    }
    const auto &pool = it->second;
    return pool[index % pool.size()];
}

// -----------------------------------------------------
// 获取学生名字
// -----------------------------------------------------
std::string NameGenerator::getStudentName(Language lang, int index) const {
    auto it = studentPools.find(lang);
    if (it == studentPools.end() || it->second.empty()) {
        return "UnknownStudent";
    }
    const auto &pool = it->second;
    return pool[index % pool.size()];
}

} // namespace edu
