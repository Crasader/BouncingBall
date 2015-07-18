<GameProjectFile>
  <PropertyGroup Type="Node" Name="Cannon" ID="6a80b1e9-3291-4910-b0d0-9a4956d7e994" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="5" Speed="0.1667" ActivedAnimationName="Shoot">
        <Timeline ActionTag="-1721826314" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="resources-2x/cannon1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="1" Tween="False">
            <TextureFile Type="Normal" Path="resources-2x/cannon1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="2" Tween="False">
            <TextureFile Type="Normal" Path="resources-2x/cannon2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="resources-2x/cannon3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="4" Tween="False">
            <TextureFile Type="Normal" Path="resources-2x/cannon4.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="resources-2x/cannon1.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Shoot" StartIndex="1" EndIndex="6">
          <RenderColor A="255" R="220" G="220" B="220" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Cannon" Tag="85" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="cannon" ActionTag="-1721826314" Tag="86" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-90.0000" RightMargin="-90.0000" TopMargin="-156.0000" BottomMargin="-44.0000" ctype="SpriteObjectData">
            <Size X="180.0000" Y="200.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.2200" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.3433" Y="3.7736" />
            <FileData Type="Normal" Path="resources-2x/cannon1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>