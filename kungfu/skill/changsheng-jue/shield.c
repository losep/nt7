#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用长生决来提升自己的防御力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的内力不够。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIW "$N" HIW "双手平举过顶，运起长生决"
                        "内劲，全身笼罩在劲气之中！\n" NOR;

        data = ([
             "armor": skill/2, 
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "长生决·护体神功",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的长生决运行完毕，将内力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;       
}
