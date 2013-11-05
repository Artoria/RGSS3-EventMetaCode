 cmd("显示文章", 101);
  start();
    entity("脸图", "string");
    entity("编号", "number");
    enumcase("窗口背景", "普通窗口", "透明背景", "暗色窗口", end_item());
    enumcase("窗口位置", "居上", "居中", "居下", end_item());
  stop();
  
  cmd("选项", 102);
  start();
    entity("选项", "stringlist");
    enumcase("取消的情况", "无效", "选项1", "选项2", "选项3", "选项4", end_item());
  stop();
  
  cmd("数值输入", 103);
  start();
    entity("接受数值的变量", "var");
    entity("最大数码", "number");
  stop();
  
  cmd("物品选择", 104);
  start();
    entity("接受物品的变量", "var");
    entity("最大数码", "number");
  stop();
  
  cmd("滚动字幕", 105);
  start();
    entity("卷动速度", "number");
    enumcase("快进", "是", "否", end_item());
  stop();
  
  cmd("注释", 108);
  start();
    entity("注释", "string");
  stop();
  
  cmd("条件分歧", 111);
  start();
    selectcase("开关", "变量", "独立开关", "计时器", "角色", "敌人", "事件", "物品", "武器", "护甲", "按下按钮", "脚本", "载具", end_item());

        casewhen(0); 
          start();
            entity("开关编号", "switch");
            enumcase("被",  "打开", "关闭",  end_item());
          stop();
        
        casewhen(1);
          start();
            entity("变量编号", "var");
            selectcase("常量", "变量", end_item());
              casewhen(0); start(); entity("常量", "number"); stop(); 
              casewhen(1); start(); entity("变量", "var"); stop();
            ;
            enumcase("关系", "等于", "以上", "以下", "大于", "小于", "不等于", end_item());
          stop();
          
        casewhen(2);
        start();
           entity("独立开关名", "selfswitch");
           enumcase("被", "打开", "关闭",  end_item());
        stop();
        
        casewhen(3);
        start();
           enumcase("计时器的时间", "不小于", "不大于", end_item());
           entity("时间", "number");
        stop();
        
        casewhen(4);
        start();
           selectcase("在队伍时", "名字是", "职业是", "技能学会", "武器装备", "防具装备", "状态有", end_item());
            casewhen(1); start(); entity("名字", "string"); stop();
            casewhen(2); start(); entity("职业", "class"); stop();
            casewhen(3); start(); entity("技能", "skill"); stop();
            casewhen(4); start(); entity("武器", "weapon"); stop();
            casewhen(5); start(); entity("防具", "armor"); stop();
            casewhen(6); start(); entity("状态", "state"); stop();
           ;
        stop();
        
        casewhen(5);
        start();
          entity("敌人", "enemy_index");
          selectcase("在", "出现", "状态是");
          start();
            casewhen(1); start(); entity("状态", "state"); stop();
          stop();
        stop();
        
        casewhen(6);
        start();
          entity("事件", "map_event");
          entity("面向", "direction");
        stop();
         
        casewhen(7);
        start();
          entity("值", "number");
          enumcase("比较", "以上", "以下", "低于", end_item());
        stop();
      
        casewhen(8);
        start();
          entity("物品", "item");
        stop();
        
        casewhen(9);
        start();
          entity("武器", "weapon");
          enumcase("包含已装备的", "否", "是", end_item());
        stop();
        
        casewhen(10);
        start();
          entity("防具", "weapon");
          enumcase("包含已装备的", "否", "是", end_item());
        stop();
        
        casewhen(11);
        start();
          entity("按钮", "symbol");
        stop();
        
        casewhen(12);
        start();
          entity("脚本", "string");
        stop();
        
        casewhen(13);
        start();
          entity("载具", "vehicle");
        stop();
        
     ;   

  stop();
  
  cmd("调用公共事件", 117);
  start();
    entity("公共事件", "commonevent");
  stop();
  
  cmd("标签跳转", 119);
  start();
    entity("标签名", "string");
  stop();
  
  cmd("开关操作", 121);
  start();
    entity("从", "switch");
    entity("到", "switch");
    enumcase("操作", "打开", "关闭", end_item());
  stop();
  
  cmd("变量操作", 122);
  start();
    entity("从", "var");
    entity("到", "var");
    enumcase("操作", "代入", "加上", "减去", "乘以", "除以", "取余", end_item());
    selectcase("常量", "变量", "随机数", "游戏数据", "脚本", end_item());
      casewhen(0); start(); entity("常数", "number"); stop();      
      casewhen(1); start(); entity("变量", "var"); stop();
      casewhen(2); start(); entity("随机数", "number");entity("随机数", "number"); stop();
      casewhen(4); start(); entity("脚本", "string"); stop();
      casewhen(3); start();
         selectcase("物品数量", "武器数量", "防具数量", "角色", "敌人", "地图人物", "队伍", end_item());
           casewhen(0); start(); entity("物品", "item"); stop();
           casewhen(1); start(); entity("武器", "weapon"); stop();
           casewhen(2); start(); entity("防具", "armor"); stop();
           casewhen(3); 
           start();
               entity("角色", "actor_index"); enumcase("参数", "等级", "Exp", "HP", "MP", 
              "MHP", "MMP", "ATK", "DEF", "MAT", "MDF", "AGI", "LUK"); 
            stop();
           casewhen(4); start(); entity("敌人", "enemy_index"); enumcase("参数", "HP", "MP", 
              "MHP", "MMP", "ATK", "DEF", "MAT", "MDF", "AGI", "LUK"); stop();
           casewhen(5); 
           start(); 
              entity("事件", "map_event");
              enumcase("参数", "X坐标", "Y坐标", "方向", "屏幕X坐标", "屏幕Y坐标", end_item());
           stop();  
           casewhen(6); start(); entity("队伍序号", "party_index"); stop();
           casewhen(7);
           start();
             enumcase("其他数据", "地图ID", "队伍人数", "金钱", "步数", "游戏时间", "计时器", "存档回数", "战斗回数", end_item());
           stop();
      stop();  
    stop();
    
    cmd("操作独立开关", 123); start();
      entity("独立开关名", "string"); 
      enumcase("操作", "打开", "关闭", end_item());
    stop();
    
    cmd("操作计时器", 124); start();
     selectcase("开始", "停止"); 
        casewhen(0); start(); entity("秒数", "number"); end_item(); stop();
        casewhen(1); start(); end_item(); stop();
    stop();
    
    cmd("操作金钱", 125); start();
      enumcase("操作", "增加", "减少", end_item());
        selectcase("常量", "变量", end_item());
          casewhen(0); start(); entity("常量", "number"); stop();
          casewhen(1); start(); entity("变量", "var"); stop();
    stop();
    
    cmd("增减物品", 126); start();
      entity("物品", "item");
      enumcase("操作", "增加", "减少", end_item());
        selectcase("常量", "变量", end_item());
          casewhen(0); start(); entity("常量", "number"); stop();
          casewhen(1); start(); entity("变量", "var"); stop();
    stop();
    
    cmd("增减武器", 127); start();
      entity("武器", "weapon");
      enumcase("操作", "增加", "减少", end_item());
        selectcase("常量", "变量", end_item());
          casewhen(0); start(); entity("常量", "number"); entity("包括装备的", "bool"); stop();
          casewhen(1); start(); entity("变量", "var"); entity("包括装备的", "bool"); stop();
    stop();
    
    cmd("增减防具", 128); start();
      entity("防具", "armor");
      enumcase("操作", "增加", "减少", end_item());
        selectcase("常量", "变量", end_item());
          casewhen(0); start(); entity("常量", "number"); entity("包括装备的", "bool"); stop();
          casewhen(1); start(); entity("变量", "var"); entity("包括装备的", "bool"); stop();
    stop();
    
    cmd("队伍管理",129); start();
      entity("角色", "actor");
      enumcase("入队离队", "入队", "离队");
      enumcase("初始化", "是", "否");
    stop();
    
    cmd("更改战斗BGM", 132); start(); entity("战斗BGM", "rpg::bgm"); stop();
    cmd("更改战斗结束ME", 133); start(); entity("战斗结束ME", "rpg::me"); stop();
    cmd("设置禁用存档", 134); start(); entity("禁用存档", "bool"); stop();
    cmd("设置禁用菜单", 135); start(); entity("禁用菜单", "bool"); stop();
    cmd("设置禁用遇敌", 136); start(); entity("禁用遇敌", "bool"); stop();
    cmd("设置禁用整队", 137); start(); entity("禁用整队", "bool"); stop();
    cmd("更改窗口色调", 138); start(); entity("色调", "tone"); stop();
    
    cmd("场所移动", 201); start();
      selectcase("直接指定", "变量指定", end_item());
       casewhen(0); start();
         entity("地图", "map");
         entity("X坐标", "number");
         entity("Y坐标", "number");
         entity("方向", "direction");
         enumcase("淡出", "普通", "白色", "无", end_item();
       stop();
       casewhen(1); start();
         entity("地图", "var");
         entity("X坐标", "var");
         entity("Y坐标", "var");
         entity("方向", "direction");
         enumcase("淡出", "普通", "白色", "无", end_item();
       stop();
    stop();
    
    cmd("设置载具位置", 202); start();
      entity("载具", "vehicle");
      selectcase("直接指定", "变量指定", end_item());
       casewhen(0); start();
         entity("地图", "map");
         entity("X坐标", "number");
         entity("Y坐标", "number");
       stop();
       casewhen(1); start();
         entity("地图", "var");
         entity("X坐标", "var");
         entity("Y坐标", "var");
       stop();
    stop();
    
    cmd("设置事件位置", 203); start();
      entity("事件", "event");
      selectcase("直接指定", "变量指定", "与事件交换", end_item());
       casewhen(0); start();
         entity("X坐标", "number");
         entity("Y坐标", "number");
         entity("方向", "direction");
       stop();
       casewhen(1); start();
         entity("X坐标", "var");
         entity("Y坐标", "var");
         entity("方向", "direction");
       stop();
       casewhen(2); start();
         entity("事件", "event");
         entity("", "null");
         entity("方向", "direction");
       stop();
    stop();
    
    cmd("设置画面卷动", 204); start();
       entity("方向", "direction");
       entity("距离", "number");
       entity("速度", "number");
    stop();
    
      cmd("设置移动路径", 205); start();
       entity("事件", "event");
       entity("路径", "rpg::moveroute");
      stop();
      
    cmd("载具乘降", 206); start(); stop();
    
    
    cmd("商店处理", 302); start();
      entity("物品类型", "baseitem-type");
      entity("物品id",   "baseitem-id");
      enumcase("原价",   "是", "否", end_item());
      entity("价格", "number");
      entity("只能购买", "bool");
    stop();
    
    cmd("名字输入", 303); start();
       entity("角色", "actor");
       entity("长度", "number");
    stop();
    
    cmd("增减HP", 311); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); entity("允许死亡", "bool"); stop();
        casewhen(1); start(); entity("变量", "var"); entity("允许死亡", "bool");stop();
    stop();
    
    cmd("增减MP", 312); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); stop();
        casewhen(1); start(); entity("变量", "var"); stop();
    stop();
    
    cmd("更改状态", 313); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("操作", "增加状态", "减少状态", end_item());
      entity("状态", "state");
    stop();
    
    cmd("完全恢复", 314); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
    stop();
    
    cmd("增减经验值", 315); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); entity("显示升级信息", "bool"); stop();
        casewhen(1); start(); entity("变量", "var"); entity("显示升级信息", "bool");stop();
    stop();
    
    
    cmd("增减等级", 316); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); entity("显示升级信息", "bool"); stop();
        casewhen(1); start(); entity("变量", "var"); entity("显示升级信息", "bool");stop();
    stop();
    
    cmd("增减能力值", 317); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("能力值", "MHP", "MMP", "ATK", "DEF", "MAT", "MDF", "AGI", "LUK", end_item());
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); entity("显示升级信息", "bool"); stop();
        casewhen(1); start(); entity("变量", "var"); entity("显示升级信息", "bool");stop();
    stop();
    
    cmd("增减技能", 318); start();
      entity("序号1", "actor_index");
      entity("序号2", "actor_index");
      enumcase("操作", "学会", "遗忘", end_item());
      entity("技能", "skill");
    stop();
    
    cmd("更改装备", 319); start();
      entity("角色", "actor_index");
      entity("第几个位置", "number");
      entity("什么装备", "number");
    stop();
    
    cmd("更改名字", 320); start();
      entity("角色", "actor");
      entity("名字", "string");
    stop(); 
    
    cmd("更改职业", 321); start();
      entity("角色", "actor");
      entity("职业", "class");
    stop();
    
    
    cmd("更改角色图像", 322); start();
      entity("角色", "actor");
      entity("行走图", "graphics/character");
      entity("序号", "number");
      entity("脸图", "graphics/face");
      entity("序号", "number");
    stop();
    
    cmd("更改载具图像", 323); start();
      entity("载具", "vehicle");
      entity("图像文件", "graphics/character");
      entity("序号", "number");
    stop();
    
    cmd("更改称号", 324); start();
      entity("角色", "actor");
      entity("称号", "string");
    stop();
    
    cmd("增减敌人HP", 331); start();
      entity("敌人序号", "enemy_index");
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); entity("允许死亡", "bool"); stop();
        casewhen(1); start(); entity("变量", "var"); entity("允许死亡", "bool");stop();
    stop();
    
    cmd("增减敌人MP", 332); start();
      entity("敌人序号", "enemy_index");
      enumcase("操作", "增加", "减少", end_item());
      selectcase("常量", "变量", end_item());
        casewhen(0); start(); entity("常量", "number"); stop();
        casewhen(1); start(); entity("变量", "var"); stop();
    stop();
    
    
    cmd("更改敌人状态", 333); start();
      entity("敌人序号", "enemy_index");
      enumcase("操作", "增加状态", "减少状态", end_item());
      entity("状态", "state");
    stop();
    
    
    cmd("敌人恢复", 334); start();
      entity("敌人序号", "enemy_index");
    stop();
    
    
    cmd("敌人出现", 335); start();
      entity("敌人序号", "enemy_index");
    stop();
    
    
     cmd("敌人变身", 337); start();
      entity("敌人序号", "enemy_index");
      entity("敌人ID", "enemy");
    stop();
    
    
    cmd("显示战斗动画", 337); start();
      entity("敌人序号", "enemy_index");
      entity("动画", "animation");
    stop();
    
    cmd("强制战斗", 339); start();
       selectcase("敌人", "角色", end_item());
          casewhen(0); start(); 
            entity("敌人", "enemy_index"); 
            entity("技能", "skill");
            entity("目标", "battletarget"); 
          stop();
          casewhen(1); start(); 
            entity("角色", "actor_index"); 
            entity("技能", "skill");
            entity("目标", "battletarget"); 
          stop();
       
       
    stop();
    
    
    cmd("中止战斗", 340); start(); stop();
    cmd("打开菜单画面", 351);start(); stop();
    cmd("打开存档画面", 352);start(); stop();
    cmd("游戏结束", 353);start(); stop();
    cmd("返回标题画面", 354);start(); stop();
    cmd("脚本", 355);start(); stop();
    start();
      entity("脚本", "string");
    stop();
    
    cmd("脚本内容", 655);
    start();
      data("string");
    stop();
    
   
    cmd("文章内容", 401);
    start();
      data("string");
    stop();
   
    cmd("字幕内容", 405);
    start();
      data("string");
    stop();
    
    cmd("注释内容", 408);
    start();
      data("string");
    stop();
    
    cmd("商店内容", 605);
    start();
      entity("物品类型", "baseitem-type");
      entity("物品id",   "baseitem-id");
      enumcase("原价",   "是", "否", end_item());
      entity("价格", "number");
    stop();
