// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m米肆兵散[2;37;0m[2;37;0m", ({"kossandpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是散兵肆米的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kossand");
        set("owner_name", "散兵肆米");
        set_temp("owner", "kossand");
        set_temp("owner_name", "散兵肆米");
        ::setup();
}
