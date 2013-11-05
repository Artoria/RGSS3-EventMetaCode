module EventEditorMeta
  def thing
   #place meta.c here
  end
end


class EventDisplay
  include EventEditorMeta
  def parse(eventlist)
    @str = ""
    eventlist.each{|x|
      @enable =  {}
      @case  = {}
      @event = x
      @posstack = []
      @pos = -1
      @kstr = ""
      thing
    }
    msgbox_p self
    @str
  end
  
  def cmd(name, id)
    if @pos == -1 && @event.code == id
      @kstr = name + ":\n"
      @enable[@pos] = true
    else
      @enable[@pos] = false
    end
  end
  
  def start()
    (@start ||= 0)
    @start += 1
    @enable[@pos + 1] = @enable[@pos]
    @posstack.push @pos
    @pos += 1 
  end
  
  def stop
    (@stop ||= 0)
    @stop += 1
    if @pos == @event.parameters.size && @enable[@pos]
      @str << ">" * (4*@event.indent) << @kstr << "\n"
      @enable[@pos] = false  
    end
    @pos -= 1 if @pos == @event.parameters.size
    @enable[@pos] = false
    @case[@pos] = false
    @pos = @posstack.pop
    
  end
  
  def moveon
    @enable[@pos + 1] = true
    @pos += 1
  end
  
  def entity(a, b)
    return unless @enable[@pos]
    @kstr << "#{a} #{b}(#{@event.parameters[@pos]})\n"
    moveon
  end
  
  def end_item 
    nil
  end
  
  def selectcase(*names, enditem)
    return unless @enable[@pos]
    @kstr << names[@event.parameters[@pos]] << "\n"
    @case[@pos] = true
  end
  
  def enumcase(caption, *names, enditem)
    return unless @enable[@pos]
    case @event.parameters[@pos] 
      when false then r = 0
      when true  then r = 1
      else r = @event.parameters[@pos]
    end
    @kstr << "#{caption} #{names[r]}\n"
    moveon
 end
  
  def casewhen(id)
    return unless @case[@pos]
    if @event.parameters[@pos] == id
      @enable[@pos] = true
    else
      @enable[@pos] = false
    end
  end
  
    
  def data(types = "string")
    return unless @enable[@pos]
    @kstr << @event.parameters.join("\n")
    @event.parameters.size.times{moveon}
  end
end
