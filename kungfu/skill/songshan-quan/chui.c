#include <ansi.h>
#include <combat.h>

#define CHUI "「" HIG "千斤锤" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if( userp(me) && !query("can_perform/songshan-quan/chui", me) )
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHUI "只能对战斗中的对手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(CHUI "只能空手施展。\n");

        if ((int)me->query_skill("songshan-quan", 1) < 30)
                return notify_fail("你嵩山拳法不够娴熟，难以施展" CHUI "。\n");;

        if (me->query_skill_prepared("cuff") != "songshan-quan")
                return notify_fail("你没有准备嵩山拳法，难以施展" CHUI "。\n");

        if (me->query_skill("force") < 40)
                return notify_fail("你的内功修为不够，难以施展" CHUI "。\n");

        if( query("neili", me)<120 )
                return notify_fail("你现在的真气不够，难以施展" CHUI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");

        msg = HIC "\n$N" HIC "双拳挥出，施一招「" HIG "千斤锤"
              HIC "」，拳速极快，部位极准，" HIC "分袭$n" HIC "面"
              "门和胸口。\n" NOR;
        
        message_sort(msg, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("songshan-quan", 1);
                damage += random(damage / 2);

                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35,
                                          HIR "$N" HIR "出手既快，方位又奇，$n"
                                          HIR "闪避不及，闷哼一声，已然中拳。\n" NOR);

                addn("neili", -100, me);
                me->start_busy(2 + random(2));                                         
        } else
        {
                msg = CYN "$n" CYN "不慌不忙，以快打快，将$N"
                      CYN "这招化去。\n" NOR;

                addn("neili", -30, me);
                me->start_busy(2 + random(3));
        }
        message_vision(msg, me, target);
        return 1;
}