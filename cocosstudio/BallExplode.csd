<GameProjectFile>
  <PropertyGroup Type="Node" Name="BallExplode" ID="b387b1b2-a4a5-4ae4-a1ab-28d0d1586116" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="3" Speed="0.3333" ActivedAnimationName="Explode">
        <Timeline ActionTag="2132910788" Property="FileData">
          <TextureFrame FrameIndex="1" Tween="False">
            <TextureFile Type="Normal" Path="asset/explode1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="2" Tween="False">
            <TextureFile Type="Normal" Path="asset/explode2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="asset/expload3.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Explode" StartIndex="1" EndIndex="4">
          <RenderColor A="150" R="205" G="92" B="92" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="BallExplode" Tag="78" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="explode1_1" ActionTag="2132910788" Tag="79" IconVisible="False" LeftMargin="-29.4011" RightMargin="-30.5989" TopMargin="-28.7535" BottomMargin="-31.2465" ctype="SpriteObjectData">
            <Size X="60.0000" Y="60.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="0.5989" Y="-1.2465" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/explode1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>