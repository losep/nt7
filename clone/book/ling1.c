#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(CYN "圣火令" NOR, ({ "shenghuo ling", "shenghuo", "ling" }) );
        set_weight(1000);
        /*if (clonep())
                destruct(this_object());
        else*/
        {
                set("unit", "柄");
                set("value", 10000);
                set("material", "steel");
                set("no_sell", "他奶奶的，这种破铁牌也值钱？");
                set("long", NOR + CYN "
这是一柄两尺来长的黑牌，非金非铁。质地坚硬无比，似透明
令中隐隐似有火焰飞腾，实则是令质映光，颜色变幻。令上刻
得有不少波斯文，似乎和武学有关，内容深奥，看来要仔细研
读一番才行。\n" NOR);
                set("wield_msg", HIR "$N" HIR "“唰”的一声，从腰间抽出一片黑黝的铁牌握在手中。\n" NOR);
                set("unwield_msg", HIR "$N" HIR "将圣火令插回腰间。\n" NOR);
                set("skill", ([
                        "name":         "shenghuo-ling",
		                "family_name" : "明教",
                        "exp_required": 1000000,
                        "jing_cost":    80,
                        "difficulty":   46,
                        "max_skill":    49,
                        "min_skill":    0,
                        "need" : ([ "sanscrit" : 150 ]),
                ]) );
        }
        init_sword(80);
        setup();
}