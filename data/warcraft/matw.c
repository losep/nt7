// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叁黄[2;37;0m[2;37;0m", ({"matwpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是黄叁的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matw");
        set("owner_name", "黄叁");
        set_temp("owner", "matw");
        set_temp("owner_name", "黄叁");
        ::setup();
}
